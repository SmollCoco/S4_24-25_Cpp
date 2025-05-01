#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::ifstream input("data.txt");
    if (!input.is_open()) {
        std::cerr << "Failed to open file \"data.txt\"" << std::endl;
        return 1;
    }
    std::ofstream output("report.txt");
    if (!output.is_open()) {
        std::cerr << "Failed to open file \"report.txt\"" << std::endl;
        return 2;
    }

    std::cout << std::fixed << std::setprecision(2);
    output << std::setw(20) << std::left << "Name" << std::setw(10) << "Age" << std::setw(15) << "Salary" << std::endl;

    std::string line;
    std::string name;
    int age;
    float salary;
    output << std::fixed << std::setprecision(2);
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        if (iss >> name >> age >> salary) {
            output << std::setw(20) << std::left << name << std::setw(10) << age << std::setw(15) << salary << std::endl;
        }
    }
    
    input.close();
    output.close();
    std::cout << "Report successfully generated in \"report.txt\"" << std::endl;

    return 0;
}
