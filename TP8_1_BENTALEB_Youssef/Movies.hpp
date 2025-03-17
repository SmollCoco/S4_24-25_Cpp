#include <iostream>
#include <vector>
#include "Movie.hpp"

class Movies {
public:
    vector<Movie> movies;
    Movies();
    ~Movies();
    bool add_movie(string n, string r, int w);
    bool increment_watched(string n);
    void display();
};
