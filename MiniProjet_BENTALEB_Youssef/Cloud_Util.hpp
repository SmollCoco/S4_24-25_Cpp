#ifndef CLOUD_UTIL_HPP
#define CLOUD_UTIL_HPP

#include "KubernetesCluster.hpp"
#include <memory>
#include <vector>

// Forward declarations
class KubernetesCluster;
class Pod;

void display(const KubernetesCluster& cluster);  // Affiche les métriques du cluster
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);  // Déploie plusieurs pods

#endif // CLOUD_UTIL_HPP
