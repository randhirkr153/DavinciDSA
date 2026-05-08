#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;

    Node(int v) {
        val = v;
        prev = next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }

    // Get value at index
    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node* temp;

        // Optimization: choose direction
        if (index < size / 2) {
            temp = head;
            for (int i = 0; i < index; i++)
                temp = temp->next;
        } else {
            temp = tail;
            for (int i = size - 1; i > index; i--)
                temp = temp->prev;
        }

        return temp->val;
    }

    // Add at head
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Add at tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Add at index
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        Node* newNode = new Node(val);

        newNode->prev = temp->prev;
        newNode->next = temp;

        temp->prev->next = newNode;
        temp->prev = newNode;

        size++;
    }

    // Delete at index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (size == 1) {
            delete head;
            head = tail = NULL;
        } 
        else if (index == 0) {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        } 
        else if (index == size - 1) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        } 
        else {
            Node* temp = head;
            for (int i = 0; i < index; i++)
                temp = temp->next;

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;
        }

        size--;
    }

    // Print list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Driver
int main() {
    MyLinkedList list;

    list.addAtHead(10);
    list.addAtHead(5);
    list.addAtTail(20);
    list.addAtIndex(1, 7);

    list.printList(); // 5 <-> 7 <-> 10 <-> 20

    cout << "Value at index 2: " << list.get(2) << endl;

    list.deleteAtIndex(1);
    list.printList(); // 5 <-> 10 <-> 20

    return 0;
}