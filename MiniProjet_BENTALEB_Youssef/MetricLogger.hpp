#include "KubernetesCluster.hpp"
#include <fstream>
#include <iostream>
#include <string>

template<typename T>
class MetricLogger {
public:
    // Constructeur
    MetricLogger() = default;
    // Destructeur
    ~MetricLogger() = default;
    // Méthode pour initialiser le logger
    void logToStream(const T& metric_name, std::ofstream& output_stream, std::string filename) {
        output_stream.open(filename, std::ios::app); // Append mode
        if (!output_stream.is_open()) {
            throw std::runtime_error("Erreur d'ouverture du fichier " + filename);
        }
        output_stream << metric_name.getMetrics() << std::endl;
        output_stream.close();
    }
};
