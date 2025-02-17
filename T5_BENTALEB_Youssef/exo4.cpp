#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

void top_frequent_words(const string& text, int n) {
    map<string, int> freq;
    istringstream iss(text);
    string word;
    // Count word frequencies
    while (iss >> word) {
        freq[word]++;
    }
    // Convert map to vector for sorting
    vector<pair<string, int>> sorted_words(freq.begin(), freq.end());
    // Sort in descending order of frequency
    sort(sorted_words.begin(), sorted_words.end(), [](pair<string, int> a, pair<string, int> b) { return a.second > b.second; });
    // Print top N frequent words
    std::cout << "Top " << n << " mots les plus fréquents :\n";
    for (int i = 0; i < n && i < sorted_words.size(); ++i) {
        std::cout << i + 1 << ". " << sorted_words[i].first << " -> " << sorted_words[i].second << "\n";
    }
}

int main() {
    std::string text = "C++ est rapide, C++ est puissant, C++ est utilisé";
    top_frequent_words(text, 3);
    return 0;
}
