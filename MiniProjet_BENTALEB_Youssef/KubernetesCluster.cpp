#include "CloudExceptions.hpp"
#include "KubernetesCluster.hpp"
#include <iostream>
#include <utility>

void KubernetesCluster::addNode(std::shared_ptr<Server> node) {
    nodes_.push_back(node);
}

bool KubernetesCluster::removePod(const std::string& name) {
    for (auto it = pods_.begin(); it != pods_.end(); ++it) {
        if ((*it)->getName() == name) {
            pods_.erase(it);
            return true;
        }
    }
    return false;
}

void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod) {
    if (nodes_.empty()) {
        throw AllocationException("Pas de serveurs disponibles dans le cluster pour le pod " + pod->getName());
    }
    bool hasActiveServer = false;
    for (const auto& node : nodes_) {
        if (node->isActive()) {
            hasActiveServer = true;
            break;
        }
    }
    if (!hasActiveServer) {
        throw ServerInactiveException("Pas de serveurs actifs dans le cluster pour le pod " + pod->getName());
    }
    
    try {
        if (schedulePod(*pod)) {
            pods_.push_back(std::move(pod));
        } else {
            throw AllocationException("Impossible de planifier le pod " + pod->getName() + " sur un serveur actif.");
        }
    } catch (const AllocationException& e) {
        throw AllocationException("Erreur de planification du pod " + pod->getName() + ": " + e.what());
    }
}

bool KubernetesCluster::schedulePod(Pod& pod) {
    double total_cpu = 0.0;
    double total_memory = 0.0;
    for (const auto& container : pod.getContainers()) {
        total_cpu += container->getCpu();
        total_memory += container->getMemory();
    }
    for (const auto& node : nodes_) {
        if (!node->isActive()) {
            continue; // Skip inactive nodes
        }
        try {
            if (node->allocate(total_cpu, total_memory)) {
                pod.deploy();
                return true;
            }
        } catch (const AllocationException& e) {
            continue;
        }
    }
    return false;
}

Pod* KubernetesCluster::getPod(const std::string& name) {
    for (const auto& pod : pods_) {
        if (pod->getName() == name) {
            return pod.get();
        }
    }
    return nullptr;
}

std::string KubernetesCluster::getMetrics() const {
    std::string metrics = "[KubernetesCluster : ";
    for (const auto& node : nodes_) {
        metrics += node->getMetrics() + ", ";
    }
    for (const auto& pod : pods_) {
        metrics += pod->getMetrics() + ", ";
    }
    metrics += "]";
    return metrics;
}

std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c) {
    os << c.getMetrics();
    return os;
}

std::vector<std::shared_ptr<Server>> KubernetesCluster::getFilteredServers(std::function<bool(const Server&)> filter) {
    std::vector<std::shared_ptr<Server>> filtered_servers;
    for (const auto& server : nodes_) {
        if (filter(*server)) {
            filtered_servers.push_back(server);
        }
    }
    return filtered_servers;
}

std::vector<std::unique_ptr<Pod>>& KubernetesCluster::getPods() {
    return pods_;
}

const std::vector<std::unique_ptr<Pod>>& KubernetesCluster::getPods() const {
    return pods_;
}
