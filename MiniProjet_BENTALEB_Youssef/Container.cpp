#include "Container.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

Container::Container(std::string id, std::string image, double cpu, double memory) : Resource{id, cpu, memory}, image_{image} {}

void Container::start() {
    Resource::start();
}

void Container::stop() {
    Resource::stop();
}

std::string Container::getMetrics() const {
    std::ostringstream oss;
    oss << "[Container: " << std::left << std::setw(10) << id_ << ": "
        << std::setw(2) << cpu_ << " CPU, "
        << std::setw(6) << memory_ << " Memory, "
        << image_ << " ]";
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
}
