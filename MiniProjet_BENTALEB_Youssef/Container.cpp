#include "Container.hpp"
#include <iostream>
#include <string>

Container::Container(std::string id, std::string image, double cpu, double memory) : Resource{id, cpu, memory}, image_{image} {}

void Container::start() {
    Resource::start();
}
void Container::stop() {
    Resource::stop();
}

std::string Container::getMetrics() const {
    return "[Container : " + id_ + " : " + std::to_string(cpu_) + ", " + std::to_string(memory_) + ", " + image_ + "]";
}
std::ostream& operator<<(std::ostream& os, const Container& c) {
    os << c.getMetrics();
    return os;
}
