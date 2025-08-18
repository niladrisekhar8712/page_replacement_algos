//
// Created by Niladri on 18-Aug-25.
//

#ifndef NODE_H
#define NODE_H


template <typename K>
class Node {
public:
    K data;
    int freq; // used for LFU
    Node<K>* prev;
    Node<K>* next;

    Node(K value) : data(value), prev(nullptr), next(nullptr) {}
};



#endif //NODE_H
