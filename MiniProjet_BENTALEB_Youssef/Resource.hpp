#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>

class Resource {
// Classe abstraite servant de base pour toutes les ressources
protected:
    std::string id_;  // identifiant unique
    double cpu_;  // capacité CPU
    double memory_;  // mémoire
    bool active_;  // état
public:
    Resource(std::string id, double cpu, double memory);  // Constructeur
    virtual void start() = 0;  // Démarre la ressource
    virtual void stop() = 0;  // Arrête la resource
    virtual std::string getMetrics() const = 0;  // Retourne les métriques
    virtual ~Resource() = default;  // Destructeur virtuel
};

#endif // RESOURCE_HPP
