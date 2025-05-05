#ifndef CLOUD_UTIL_HPP
#define CLOUD_UTIL_HPP

#include "KubernetesCluster.hpp"
#include <memory>
#include <vector>

void display(const KubernetesCluster& cluster);  // Affiche les métriques du cluster
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);  // Déploie plusieurs pods
void saveClusterMetrics(const KubernetesCluster& cluster, const std::string& filename);  // Enregistre les métriques du cluster dans un fichier
void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func);

#endif
