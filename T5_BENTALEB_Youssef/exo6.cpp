#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool contains_email(const string& text) {
    // Define the regex pattern for an email address
    regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    // Use regex_search to check if the text contains an email address
    smatch match;
    if (regex_search(text, match, email_pattern)) {
        cout << "Adresse email détectée : " << match.str() << endl;
        return true;
    } else {
        cout << "Aucune adresse email détectée." << endl;
        return false;
    }
}

int main() {
    string text = "Mon email est user@example.com";
    contains_email(text);
    return 0;
}
