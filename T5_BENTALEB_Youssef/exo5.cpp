#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

void sort_by_length(const string& text) {
    multimap<int, string> word_map;
    istringstream iss(text);
    string word;
    // Count word frequencies
    while (iss >> word) {
        word_map.insert({word.size(), word});
    }
    std::cout << "Trie par longueur : ";
    for (auto pair : word_map) {
        cout << pair.second << ' ';
    }
    cout << endl;
}

int main() {
    string phrase = "Le langage C++ est rapide et efficace";
    sort_by_length(phrase);
    return 0;
}
