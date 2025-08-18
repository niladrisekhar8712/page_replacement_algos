#include <unordered_map>
#include "DoublyLinkedList.h"
using namespace std;
class LeastFrequentlyUsed {
    unordered_map<int, Node<int>*> keyMap;
    unordered_map<int, DoublyLinkedList<int>*> freqMap;
    int size;
    int capacity;
    int leastFreq;


    void updateFrequency(Node<int>* node) {
        keyMap.erase(node->data);
        freqMap[node->freq]->remove_node(node);

        if (freqMap[node->freq]->size == 0 && leastFreq == node->freq) {
            leastFreq++;
        }

        DoublyLinkedList<int>* nextHigherFreq = new DoublyLinkedList<int>();

        if (freqMap.find(node->freq+1) != freqMap.end()) {
            nextHigherFreq = freqMap[node->freq+1];
        }
        node->freq ++;
        nextHigherFreq->push_front(node);
        freqMap[node->freq] = nextHigherFreq;
        keyMap[node->data] = node;
    }

public:
    LeastFrequentlyUsed(int capacity) : capacity(capacity) {
        size = 0;
        keyMap.clear();
        freqMap.clear();
    }
    ~LeastFrequentlyUsed() {
        for (auto& it : freqMap) {
            delete it.second;
        }
    }

    bool access(int page) {
        // exists
        if (keyMap.find(page) != keyMap.end()) {
            Node<int>* node = keyMap[page];
            updateFrequency(node);
            return true;
        }
        // does not exist
        if (capacity == 0) return false;

        if (size == capacity) {
            keyMap.erase(freqMap[leastFreq]->tail_ptr()->data);
            freqMap[leastFreq]->pop_back();
            size--;
        }
        leastFreq = 1;
        DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
        if (freqMap.find(leastFreq) != freqMap.end()) {
            list = freqMap[leastFreq];
        }
        Node<int>* node = new Node<int>(page);
        list->push_front(node);
        node->freq = 1;
        keyMap[page] = node;
        freqMap[leastFreq] = list;
        size++;
        return false;
    }
    unordered_map<int, Node<int>*> getKeyMap() {
        return keyMap;
    }
};