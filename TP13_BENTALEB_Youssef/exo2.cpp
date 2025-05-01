#include <functional>
#include <iostream>
#include <vector>

void filter(std::vector<int> arr, std::function<bool(int)> predicat) {
    for (int x : arr) {
        if (predicat(x)) {
            std::cout << x << ' ';
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {10, 15, 20, 25, 30, 50, 75};
    auto predicat_1 = [=](int x){ return x > 20; };
    auto predicat_2 = [=](int x){ return x % 2 == 0; };

    filter(arr, predicat_1);
    filter(arr, predicat_2);

    return 0;
}
