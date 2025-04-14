#ifndef POD_HPP
#define POD_HPP

#include "Container.hpp"
#include <memory>
#include <unordered_map>
#include <vector>
#include <iostream>

// Forward declarations
class Container;

class Pod {
// Ne hérite pas de Resource, mais gère des conteneurs
private:
    std::string name_;  // nom du pod
    std::vector<std::unique_ptr<Container>> containers_;
    std::unordered_map<std::string, std::string> labels_;  // métadonnées
public:
    Pod(std::string name, std::unordered_map<std::string, std::string> labels = {});  // Constructeur
    std::string getName() const { return name_; }  // Récupère le nom
    void addContainer(std::unique_ptr<Container> container);  // Ajoute un conteneur
    bool removeContainer(const std::string& id);  // Supprime un conteneur
    void deploy();  // Démarre tous les conteneurs
    std::string getMetrics() const;  // Agrège les métriques des conteneurs
    friend std::ostream& operator<<(std::ostream& os, const Pod& p);  // Affiche le nom et les conteneurs
    const std::vector<std::unique_ptr<Container>>& getContainers() const;  // Récupère les conteneurs
};

#endif // POD_HPP
