#include "Movies.h"

bool Movies::add_movie(string n, string r, int w) {
    for (auto m : movies) {
        if (m.get_name() == n) {
            return false;
        }
    }
    Movie new_movie {n, r, w};
    movies.push_back(new_movie);
    return true;
}
bool Movies::increment_watched(string n) {
    for (auto& m : movies) {
        if (m.get_name() == n) {
            m.set_watched(m.get_watched() + 1);
            return true;
        }
    }
    return false;
}
void Movies::display() {
    if (movies.size() == 0) {
        cout << "Desole, aucun film a afficher" << endl;
        cout << endl;
        return;
    }
    cout << "===================================" << endl;
    cout << endl;
    for (auto m : movies) {
        m.display();
    }
    cout << "===================================" << endl;
    cout << endl;
}
