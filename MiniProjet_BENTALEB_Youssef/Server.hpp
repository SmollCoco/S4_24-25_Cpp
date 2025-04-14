#ifndef SERVER_HPP
#define SERVER_HPP

#include "Resource.hpp"
#include <memory>
#include <iostream>
#include <string>

// Forward declarations
class Resource;

class Server : public Resource {
// Hérite de : Resource
private:
    double available_cpu_;  // CPU disponible
    double  available_memory_; // mémoire disponible
public:
    Server(std::string id, double cpu, double memory);  // Constructeur
    bool allocate(double cpu, double memory);  // Alloue des ressources si disponibles
    void start() override;  // Active le serveur
    void stop() override;  // Désactive le serveur
    std::string getMetrics() const override;  // Format : [Server : id : CPU, Memory, Available CPU, Available Memory]
    friend std::ostream& operator<<(std::ostream& os, const Server& s);  // Même format que getMetrics
};

#endif // SERVER_HPP
