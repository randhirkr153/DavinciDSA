#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            deleteNode(existing);
            mp.erase(key);
        }

        if (mp.size() == capacity) {
            Node* lru = tail->prev;
            deleteNode(lru);
            mp.erase(lru->key);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

// Driver
int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl; // 10

    cache.put(3, 30); // removes key 2

    cout << cache.get(2) << endl; // -1

    return 0;
}