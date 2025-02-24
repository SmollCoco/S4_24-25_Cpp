#include <iostream>
using namespace std;

// Structure représentant un noeud de l'arbre
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructeur pour initialiser un noeud
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    // Fonction pour insérer un élément dans l'arbre
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);  // Crée un nouveau noeud si l'endroit est libre
        }
        if (value < node->data) {
            node->left = insert(node->left, value);  // Insertion à gauche si la valeur est plus petite
        } else {
            node->right = insert(node->right, value);  // Insertion à droite si la valeur est plus grande
        }
        return node;
    }
    // Fonction pour rechercher un élément dans l'arbre
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;  // La valeur n'existe pas
        }
        if (value == node->data) {
            return true;  // La valeur est trouvée
        }
        if (value < node->data) {
            return search(node->left, value);  // Recherche à gauche
        } else {
            return search(node->right, value);  // Recherche à droite
        }
    }
    // Fonction pour supprimer un élément de l'arbre
    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return node;  // Si l'arbre est vide, rien à supprimer
        }
        if (value < node->data) {
            node->left = remove(node->left, value);  // Recherche à gauche
        } else if (value > node->data) {
            node->right = remove(node->right, value);  // Recherche à droite
        } else {
            // Noeud trouvé
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;  // Retourne le sous-arbre droit
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;  // Retourne le sous-arbre gauche
            }
            // Noeud avec deux enfants
            Node* temp = minValueNode(node->right);  // Trouve le minimum dans le sous-arbre droit
            node->data = temp->data;
            node->right = remove(node->right, temp->data);  // Supprime l'élément trouvé dans le sous-arbre droit
        }
        return node;
    }
    // Trouver le noeud avec la valeur minimale dans un sous-arbre
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    // Fonction récursive pour afficher l'arbre en parcours infixe (in-order)
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);  // Parcours à gauche
            cout << node->data << " ";  // Affiche la valeur du noeud
            inorder(node->right);  // Parcours à droite
        }
    }
public:
    // Constructeur
    BST() : root(nullptr) {}
    // Insertion d'une valeur dans l'arbre
    void insert(int value) {
        root = insert(root, value);
    }
    // Recherche d'une valeur dans l'arbre
    bool search(int value) {
        return search(root, value);
    }
    // Suppression d'une valeur de l'arbre
    void remove(int value) {
        root = remove(root, value);
    }
    // Afficher l'arbre en parcours infixe (in-order)
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST bst;
    cout << "Insertion des éléments : 5 3 7 2 4 6 8" << endl;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    cout << "Parcours infixe :" << endl;
    bst.inorder();  // Affiche l'arbre en ordre croissant
    cout << "Recherche de 4 : ";
    if (bst.search(4)) {
        cout << "Trouvé" << endl;
    } else {
        cout << "Non trouvé" << endl;
    }
    cout << "Suppression de 4" << endl;
    bst.remove(4);
    cout << "Parcours infixe après suppression :" << endl;
    bst.inorder();  // Affiche l'arbre après suppression
    return 0;
}
