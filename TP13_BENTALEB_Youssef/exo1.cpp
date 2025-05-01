#include <algorithm>
#include <iostream>
#include <vector>

struct Additioner {
    private:
        int value;
    public:
        Additioner(int value_) : value(value_) {}
        void operator()(int x) {
            std::cout << x + value<< ' ';
        }
};

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    Additioner add = {10};

    std::for_each(arr.begin(), arr.end(), add);

    return 0;
}
