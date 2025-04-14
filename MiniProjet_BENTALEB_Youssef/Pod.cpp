#include "Pod.hpp"
#include <iostream>
using namespace std;

Pod::Pod(string name, unordered_map<string, string> labels) : name_{name}, labels_{labels} {}

void Pod::addContainer(unique_ptr<Container> container) {
    containers_.push_back(move(container));
}

bool Pod::removeContainer(const std::string& id) {
    for (auto it = containers_.begin(); it != containers_.end(); ++it) {
        if ((*it)->getId() == id) {
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
    string metrics = "[Pod : " + name_ + " : ";
    for (const auto& container : containers_) {
        metrics += container->getMetrics() + ", ";
    }
    metrics += "]";
    return metrics;
}

ostream& operator<<(ostream& os, const Pod& p) {
    os << p.getMetrics();
    return os;
}

const vector<unique_ptr<Container>>& Pod::getContainers() const {
    return containers_;
}
