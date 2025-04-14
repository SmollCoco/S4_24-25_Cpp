#include "Server.hpp"
#include <iostream>
using namespace std;

Server::Server(string id, double cpu, double memory) : Resource{id, cpu, memory}, available_cpu_{cpu}, available_memory_{memory} {}

bool Server::allocate(double cpu, double memory) {
    if (cpu <= available_cpu_ && memory <= available_memory_) {
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    return false;
}

void Server::start() {
    Resource::start();
}

void Server::stop() {
    Resource::stop();
}

string Server::getMetrics() const {
    return "[Server : " + id_ + " : " + to_string(cpu_) + ", " + to_string(memory_) + ", " + to_string(available_cpu_) + ", " + to_string(available_memory_) + "]";
}

ostream& operator<<(ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
}
