#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int value;
    shared_ptr<Node> next;
    weak_ptr<Node> prev;
    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

struct LRUCache {
    int capacity;
    unordered_map<int, shared_ptr<Node>> cacheMap;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
};

void initCache(LRUCache& cache, int capacity) {
    cache.capacity = capacity;
    cache.head = make_shared<Node>(-1, -1);
    cache.tail = make_shared<Node>(-1, -1);
    cache.head->next = cache.tail;
    cache.tail->prev = cache.head;
}

void removeNode(LRUCache& cache, shared_ptr<Node> node) {
    auto prev = node->prev.lock();
    if (prev) prev->next = node->next;
    if (node->next) node->next->prev = prev;
}

void addToHead(LRUCache& cache, shared_ptr<Node> node) {
    node->prev = cache.head;
    node->next = cache.head->next;
    cache.head->next->prev = node;
    cache.head->next = node;
}

void moveToHead(LRUCache& cache, shared_ptr<Node> node) {
    removeNode(cache, node);
    addToHead(cache, node);
}

void evict(LRUCache& cache) {
    auto lruNode = cache.tail->prev.lock();
    if (lruNode != cache.head) {
        cache.cacheMap.erase(lruNode->key);
        removeNode(cache, lruNode);
    }
}

void put(LRUCache& cache, int key, int value) {
    if (cache.cacheMap.find(key) != cache.cacheMap.end()) {
        auto node = cache.cacheMap[key];
        node->value = value;
        moveToHead(cache, node);
    } else {
        if (cache.cacheMap.size() >= cache.capacity) evict(cache);
        auto newNode = make_shared<Node>(key, value);
        cache.cacheMap[key] = newNode;
        addToHead(cache, newNode);
    }
}

int get(LRUCache& cache, int key) {
    if (cache.cacheMap.find(key) == cache.cacheMap.end()) return -1;
    auto node = cache.cacheMap[key];
    moveToHead(cache, node);
    return node->value;
}

void printCache(const LRUCache& cache) {
    auto current = cache.head->next;
    cout << "Cache actuel :" << endl;
    while (current != cache.tail) {
        cout << current->key << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    LRUCache cache;
    initCache(cache, 4);
    // Accès aux clés 1 2 3 1 4
    put(cache, 1, 100);
    put(cache, 2, 200);
    put(cache, 3, 300);
    get(cache, 1);
    put(cache, 4, 400);
    std::cout << "Accès aux clés : 1 2 3 1 4" << std::endl;
    printCache(cache);
    // Accès à la clé 5
    std::cout << "Accès à la clé 5 -> Eviction de la clé 2" << std::endl;
    put(cache, 5, 500);
    printCache(cache);
    return 0;
}
