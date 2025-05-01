#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    auto add_5 = [&](int x){ return x + 5; };
    std::vector<int> arr = {10, 12, 15, 17};

    std::transform(arr.begin(), arr.end(), arr.begin(), add_5);
    for (int x : arr) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    return 0;
}
