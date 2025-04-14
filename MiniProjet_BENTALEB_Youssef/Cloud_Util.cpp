#include "Cloud_Util.hpp"
#include <iostream>
#include <vector>

void display(const KubernetesCluster& cluster) {
    std::cout << cluster.getMetrics() << std::endl;
}

void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods) {
    for (auto& pod : pods) {
        cluster.deployPod(std::move(pod));
    }
}
