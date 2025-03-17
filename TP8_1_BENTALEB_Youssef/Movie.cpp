#include <iostream>
#include <string>
#include "Movie.hpp"
using namespace std;

// Constructeur
Movie::Movie(string n, string r, int w) {
    name = n;
    rating = r;
    watched = w;
}
// Destructeur
Movie::~Movie() {}
// Setters
void Movie::set_name(string new_name) {
    name = new_name;
}
void Movie::set_rating(string new_rating) {
    rating = new_rating;
}
void Movie::set_watched(int new_watched) {
    watched = new_watched;
}
// Getters
string Movie::get_name() { 
    return name;
}
string Movie::get_rating() {
    return rating;
}
int Movie::get_watched() {
    return watched;
}
// Fonction pour afficher les infos du film
void Movie::display() {
    cout << name << ", "<< rating << ", " << watched << endl;
    cout << endl;
}
