#include "Pod.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Pod::Pod(string name, unordered_map<string, string> labels) : name_{name}, labels_{labels} {}

void Pod::addContainer(unique_ptr<Container> container) {
    containers_.push_back(move(container));
}

bool Pod::removeContainer(const std::string& id) {
    for (auto it = containers_.begin(); it != containers_.end(); ++it) {
        if ((*it)->getId() == id) {
            (*it)->stop();  // Arrêter le conteneur avant de le supprimer
            containers_.erase(it);
            return true;
        }
    }
    return false;
}

void Pod::deploy() {
    for (auto& container : containers_) {
        container->start();
    }
}

string Pod::getMetrics() const {
    ostringstream oss;
    oss << "[Pod: " << left << setw(10) << name_ << " | Containers: ";
    if (containers_.empty()) {
        oss << "None";
    } else {
        bool first = true;
        for (const auto& container : containers_) {
            if (!first) {
                oss << ", ";
            }
            oss << container->getId();
            first = false;
        }
    }
    
    oss << "]";
    return oss.str();
}

ostream& operator<<(ostream& os, const Pod& p) {
    os << p.getMetrics();
    return os;
}

const vector<unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;
}
