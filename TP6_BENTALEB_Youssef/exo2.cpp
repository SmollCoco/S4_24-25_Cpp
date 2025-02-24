#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;  // Nombre de sommets
    vector<int>* adj;  // Liste d'adjacence (tableau de vecteurs)
    // Fonction récursive pour le DFS
    void dfs(int v, bool* visited) {
        cout << v << " ";  // Affiche le sommet visité
        visited[v] = true;
        // Explorer les voisins non visités
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, visited);
            }
        }
    }
public:
    // Constructeur
    Graph(int vertices) {
        V = vertices;
        adj = new vector<int>[V];  // Allocation dynamique d'un tableau de vecteurs
    }
    // Ajout d'une arête orientée
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    // DFS à partir d'un sommet donné
    void DFS(int start) {
        bool* visited = new bool[V] {false};  // Tableau de suivi des sommets visités
        cout << "Parcours en profondeur à partir du sommet " << start << " :\n";
        dfs(start, visited);
        cout << endl;
        delete[] visited;  // Libérer la mémoire allouée
    }
    // Destructeur pour libérer la mémoire
    ~Graph() {
        delete[] adj;
    }
};

int main() {
    Graph g(4);  // Création d'un graphe à 4 sommets
    // Ajout des arêtes
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    // Effectuer un DFS depuis le sommet 0
    g.DFS(0);
    return 0;
}
