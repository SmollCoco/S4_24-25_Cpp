#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string keyword;
    std::cout << "Enter the keyword: ";
    std::getline(std::cin, keyword);

    std::ifstream input("input_file.txt");
    if (!input.is_open()) {
        std::cerr << "Error while opening file \"input_file.txt\"" << std::endl;
        return 1;
    }
    std::ofstream output("output_file.txt");
    if (!output.is_open()) {
        std::cerr << "Error while opening file \"output_file.txt\"" << std::endl;
        return 2;
    }

    std::string line;
    int count = 0;
    while (std::getline(input, line)) {
        if(line.find(keyword) != std::string::npos) {
            output << line << std::endl;
            ++count;
        }
    }

    input.close();
    output.close();
    std::cout << count << " lines containing \'" << keyword << "\' were successfully copied from \"input_file.txt\" to \"output_file.txt\"" << std::endl;
    return 0;
}
