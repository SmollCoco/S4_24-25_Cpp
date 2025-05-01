#include <iostream>
#include <vector>
#include <stdexcept>

class StackFullException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Pile pleine";
    }
};

class StackEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erreur: Pile vide";
    }
};

class Stack {
    std::vector<int> data;
    int capacity;
public:
    Stack(int cap) : capacity(cap) {}
    
    void push(int val) {
        if (data.size() >= capacity) throw StackFullException();
        data.push_back(val);
    }
    
    int pop() {
        if (data.empty()) throw StackEmptyException();
        int val = data.back();
        data.pop_back();
        return val;
    }
    
    int size() const { return data.size(); }
};

void func_c(Stack& s) {
    s.push(3); // Provoque une exception si pile pleine
}

void func_b(Stack& s) {
    func_c(s);
}

void func_a(Stack& s) {
    func_b(s);
}

int main() {
    try {
        Stack s(2);
        s.push(1);
        s.push(2);
        std::cout << "Taille pile: " << s.size() << std::endl;
        func_a(s);
    }
    catch (const StackFullException& e) {
        std::cerr << "Attrapée dans main: " << e.what() << std::endl;
    }
    
    try {
        Stack s(2);
        s.pop();
    }
    catch (const StackEmptyException& e) {
        std::cerr << "Attrapée dans main: " << e.what() << std::endl;
    }
    
    std::cout << "Programme terminé" << std::endl;
    return 0;
}