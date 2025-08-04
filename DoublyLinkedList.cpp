#include <iostream>
template <typename K>
class Node {
public:
    K data;
    Node<K>* prev;
    Node<K>* next;

    Node(K value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename K>
class DoublyLinkedList {
private:
    Node<K>* head;
    Node<K>* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head) {
            pop_back();
        }
    }

    void push_front(Node<K>* node) {
        node->prev = nullptr;
        node->next = head;

        if (head)
            head->prev = node;
        else
            tail = node;

        head = node;
    }

    void remove_node(Node<K>* node) {
        if (!node) return;

        if (node->prev)
            node->prev->next = node->next;
        else
            head = node->next;

        if (node->next)
            node->next->prev = node->prev;
        else
            tail = node->prev;

        node->next = nullptr;
        node->prev = nullptr;
    }

    int pop_back() {
        if (!tail) return -1;

        Node<K>* temp = tail;

        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = tail = nullptr;
        }
        int x = temp->data;
        temp->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return x;
    }

    Node<K>* head_ptr() const {
        return head;
    }
};
