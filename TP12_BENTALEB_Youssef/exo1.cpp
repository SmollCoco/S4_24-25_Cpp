#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
    std::ofstream output("output.txt");
    if (!output.is_open()) {
        std::cerr << "Failed to open file \"output.txt\"" << std::endl;
        return 1;
    }

    float x;
    output << std::fixed << std::setprecision(2);
    
    while (std::cout << "Enter a number (non-numeric to exit): " && std::cin >> x) {
        output << std::setw(10) << std::left << x << std::endl;
        std::cout << "Value " << x << " written" << std::endl;
    }

    std::cout << "Exiting due to non-numeric input." << std::endl;
    output.close();
    std::cout << "Numbers have been successfully written to \"output.txt\"" << std::endl;
    
    return 0;
}
