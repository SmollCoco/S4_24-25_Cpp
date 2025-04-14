#include "Resource.hpp"
#include <iostream>
using namespace std;

Resource::Resource(string id, double cpu, double memory) : id_{id}, cpu_{cpu}, memory_{memory} {
    active_ = false;
}

void Resource::start() {
    active_ = true;
}

void Resource::stop() {
    active_ = false;
}

string Resource::getMetrics() const {
    return "[" + id_ + " : " + to_string(cpu_) + ", " + to_string(memory_) + "]";
}
