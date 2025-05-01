#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Book {
    private:
        std::string title;
        int num_of_pages;
    public:
        Book(std::string title_, int num_of_pages_) : title(title_), num_of_pages(num_of_pages_) {}

        std::string getTitle() {
            return title;
        }
        int getNum_of_pages() {
            return num_of_pages;
        }

        friend std::ostream& operator<<(std::ostream& os, Book book) {
            os << book.title << " - " << book.num_of_pages << " pages";
            return os;
        }
};

int main() {
    std::vector<Book> arr = {
        {"C++ Moderne", 350},
        {"Apprendre Python", 500},
        {"Algorithmique", 450}
    };
    auto sort_by_title = [](Book a, Book b){ return a.getTitle() < b.getTitle(); };
    auto sort_by_num_of_pages = [](Book a, Book b){ return a.getNum_of_pages() < b.getNum_of_pages(); };
    
    std::sort(arr.begin(), arr.end(), sort_by_title);
    for (const auto& book : arr) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    std::sort(arr.begin(), arr.end(), sort_by_num_of_pages);
    for (const auto& book : arr) {
        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
