#ifndef KUBERNETES_CLUSTER_HPP
#define KUBERNETES_CLUSTER_HPP

#include "Pod.hpp"
#include "Server.hpp"
#include <functional>
#include <memory>
#include <string>
#include <vector>

class KubernetesCluster {
// Gère les serveurs et pods
private:
    std::vector<std::shared_ptr<Server>> nodes_;
    std::vector<std::unique_ptr<Pod>> pods_;
public:
    KubernetesCluster() = default;  // Constructeur par défaut
    void addNode(std::shared_ptr<Server> node);  // Ajoute un serveur
    bool removePod(const std::string& name);  // Supprimer un Pod
    void deployPod(std::unique_ptr<Pod> pod);  // Déploie un pod sur un serveur disponible
    bool schedulePod(Pod& pod);  // Tente de planifier un pod sur un serveur disposant de suffisamment de ressources
    Pod* getPod(const std::string& name);  // Récupère un pod par son nom
    const std::vector<std::unique_ptr<Pod>>& getPods() const;  // Récupère les pods (version const)
    std::vector<std::unique_ptr<Pod>>& getPods();  // Récupère les pods (version non-const)
    std::string getMetrics() const;  // Agrège les métriques des serveurs et pods
    friend std::ostream& operator<<(std::ostream& os, const KubernetesCluster& c);  // Affiche les serveurs et pods
    std::vector<std::shared_ptr<Server>> getFilteredServers(std::function<bool(const Server&)> filter);

};

#endif
