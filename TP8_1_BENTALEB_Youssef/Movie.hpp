#include <string>
using namespace std;

class Movie {
private:
    string name;
    string rating;
    int watched;
public:
    // Constructeur
    Movie(string n, string r, int w);
    // Destructeur
    ~Movie();
    // Setters
    void set_name(string new_name);
    void set_rating(string new_rating);
    void set_watched(int new_watched);
    // Getters
    string get_name();
    string get_rating();
    int get_watched();
    // Fonction pour afficher les infos du film
    void display();
};
