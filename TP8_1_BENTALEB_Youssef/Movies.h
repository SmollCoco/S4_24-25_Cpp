#include <iostream>
#include <vector>
#include "Movie.h"

class Movies {
public:
    vector<Movie> movies;
    bool add_movie(string n, string r, int w);
    bool increment_watched(string n);
    void display();
};
