#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "Resource.hpp"
#include <iostream>
#include <string>

class Container : public Resource {
// Hérite de : Resource
private:
    std::string image_;  // image de l'application
public:
    Container(std::string id, std::string image, double cpu, double memory);  // Constructeur
    std::string getId() const { return id_; }  // Récupère l'identifiant
    double getCpu() const { return cpu_; }  // Récupère la capacité CPU
    double getMemory() const { return memory_; }  // Récupère la mémoire
    std::string getName() const { return id_; }  // Récupère le nom
    void start() override;  // Active le conteneur
    void stop() override;  // Désactive le conteneur
    std::string getMetrics() const override;  //  Format : [Container : id : CPU, Memory, Image]
    friend std::ostream& operator<<(std::ostream& os, const Container& c);  // Même format que getMetrics
};

#endif
