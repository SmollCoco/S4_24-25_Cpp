#include<iostream>
using namespace std;

#ifndef EXO
#define EXO 1
#endif

#if (EXO == 1)
int main() {
    int C[5] = {10, 20, 30, 40, 50};
    cout << "Eléments : ";
    int somme = 0;
    for (int x : C) {
        cout << x << " ";
        somme += x;
    }
    cout << endl;
    cout << "Somme : " << somme << endl;
    return 0;
}

#elif (EXO == 2)
int main() {
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Matrice :" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int tr = 0;
    for (int i = 0; i < 3; ++i) {
        tr += matrix[i][i];
    }
    cout << "Somme diagonale : " << tr << endl;
    return 0;
}

#elif (EXO == 3)
#include <array>
int main() {
    array<int, 5> arr = {1, 2, 3, 4, 5};
    cout << "Original : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    // Inverser le tableau manuellement
    for (size_t i = 0; i < arr.size() / 2; ++i) {
        swap(arr[i], arr[arr.size() - 1 - i]);
    }
    cout << "Inversé : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}

#elif (EXO == 4)
#include <vector>
int main() {
    int n = 5;  // Taille maximale de arr
    vector<int> arr(5);  
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << "Doublé : ";
    for (int x : arr) cout << 2 * x << " ";
    cout << endl;
    return 0;
}

#elif (EXO == 5)
#include <list>
int main() {
    int n = 5;  // Taille maximale de arr
    list<int> arr = {10, 20, 30, 40, 50};  
    arr.push_back(60);
    arr.push_front(0);
    cout << "Après insertion : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}

#elif (EXO == 6)
#include <set>
int main() {
    set<int> a = {5, 10, 15, 20};
    cout << "Original : ";
    for (int x : a) cout << x << " ";
    cout << endl;
    a.insert(10);
    cout << "Après insertion de 10 : ";
    for (int x : a) cout << x << " ";
    cout << "(pas de doublons)" << endl;
    return 0;
}

#elif (EXO == 7)
#include <map>
int main() {
    map<string, int> hashmap;
    hashmap["John"] = 85;
    hashmap["Alice"] = 90;
    hashmap["Bob"] = 78;
    for (auto [k, v] : hashmap) {
        cout << k << " : " << v << endl;
    }
    return 0;
}

#elif (EXO == 8)
#include <unordered_map>
int main() {
    int n = 6;  // Nombre maximal des mots entrés
    unordered_map<string, int> hashmap;
    string k;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (hashmap.find(k) != hashmap.end()) {
            ++hashmap[k];
        } else {
            hashmap[k] = 1;
        }
    }
    for (auto [k, v] : hashmap) {
        cout << k << " : " << v << endl;
    }
    return 0;
}

#elif (EXO == 9)
#include <vector>
#include <algorithm>
int main() {
    vector<int> arr = {30, 10, 50, 20, 40};
    cout << "Original : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    sort(arr.begin(), arr.end());
    cout << "Trié : ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}

#elif (EXO == 10)
#include <set>
#include <vector>

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;
    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentStreak = 1;
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentStreak += 1;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    cout << "Plus longue séquence : " << longestStreak << endl;
    return 0;
}

#elif (EXO == 11)
#include <list>
#include <unordered_map>

int capacity;
list<pair<int, int>> lru;
unordered_map<int, list<pair<int, int>>::iterator> cache;

void init(int cap) {
    capacity = cap;
}

int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) {
        return -1;
    }
    lru.splice(lru.begin(), lru, it->second);
    return it->second->second;
}

void put(int key, int value) {
    auto it = cache.find(key);
    if (it != cache.end()) {
        lru.splice(lru.begin(), lru, it->second);
        it->second->second = value;
        return;
    }
    if (cache.size() == capacity) {
        int old_key = lru.back().first;
        lru.pop_back();
        cache.erase(old_key);
    }
    lru.emplace_front(key, value);
    cache[key] = lru.begin();
}

void display() {
    for (auto pair : lru) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;
}

int main() {
    init(2);
    put(1, 10);
    put(2, 20);
    cout << "État du cache : ";
    display();
    cout << "Accès à la clé 1 : " << get(1) << endl;
    cout << "État du cache : ";
    display();
    put(3, 30);
    cout << "Ajout de (3, 30), suppression de (2, 20)" << endl;
    cout << "État du cache : ";
    display();
    return 0;
}

#else
#error "Veuillez entrer une valeur valide pour EXO (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)"

#endif
