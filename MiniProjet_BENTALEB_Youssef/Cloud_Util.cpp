#include "CloudExceptions.hpp"
#include "Cloud_Util.hpp"
#include <fstream>
#include <iostream>
#include <vector>

void display(const KubernetesCluster& cluster) {
    std::cout << cluster.getMetrics() << std::endl;
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    for (auto& pod : pods) {
        try {
            cluster.deployPod(std::move(pod));
        } catch (const AllocationException& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    pods.clear();  // Libérer les pointeurs 
}

void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw FileException("Impossible d'ouvrir le fichier " + filename);
    }
    file << cluster.getMetrics() << std::endl;
    file.close();
}

void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    for (const auto& pod : cluster.getPods()) {
        for (const auto& container : pod->getContainers()) {
            func(*container);
        }
    }
}
