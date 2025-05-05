#include "CloudExceptions.hpp"
#include "Server.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
using namespace std;

Server::Server(string id, double cpu, double memory) : Resource{id, cpu, memory}, available_cpu_{cpu}, available_memory_{memory} {}

bool Server::allocate(double cpu, double memory) {
    if (!active_) {
        throw ServerInactiveException("Cannot allocate resources on inactive server " + id_);
    }
    if (cpu <= available_cpu_ && memory <= available_memory_) {
        available_cpu_ -= cpu;
        available_memory_ -= memory;
        return true;
    }
    throw AllocationException("Not enough resources available on server " + id_);
}

void Server::start() {
    Resource::start();
}

void Server::stop() {
    Resource::stop();
}

bool Server::isActive() const {
    return active_;
}

string Server::getMetrics() const {
    ostringstream oss;
    oss << "[Server: " << left << setw(10) << id_ 
        << " | Total: " << setw(2) << cpu_ << " CPU, " 
        << setw(6) << memory_ << " MB"
        << " | Free: " << setw(2) << available_cpu_ << " CPU, " 
        << setw(6) << available_memory_ << " MB]";
    return oss.str();
}

ostream& operator<<(ostream& os, const Server& s) {
    os << s.getMetrics();
    return os;
}
