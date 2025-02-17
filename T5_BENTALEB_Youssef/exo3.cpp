#include <iostream>

std::string encode_rle(const std::string& text) {
    std::string res = "";
    int n = text.size();
    if (!n) return "";
    char curr_char = text[0];
    int curr_count = 1;
    for (int i = 1; i < n + 1; ++i) {
        while (i < n && text[i] == curr_char) {
            ++curr_count;
            ++i;
        }
        res += std::string(1, curr_char) + std::to_string(curr_count);
        if (i >= n) break;
        curr_char = text[i];
        curr_count = 1;
    }
    return res;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << "Texte : \"" << s << "\"\n";
    std::cout << "Encodé : \"" << encode_rle(s) << "\"\n";
    return 0;
}
