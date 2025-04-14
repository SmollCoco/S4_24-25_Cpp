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
    if (schedulePod(*pod)) {
        pods_.push_back(std::move(pod));
    } else {
        std::cout << "Échec du déploiement du pod : ressources insuffisantes.\n";
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
        if (node->allocate(total_cpu, total_memory)) {
            pod.deploy();
            return true;
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
