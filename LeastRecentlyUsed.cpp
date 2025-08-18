#include <unordered_map>
#include "DoublyLinkedList.h"
#include "Node.h"

class LeastRecentlyUsed {
private:
    std::unordered_map<int, Node<int>*> map;
    DoublyLinkedList<int>* list;
    int capacity;


public:
    LeastRecentlyUsed(int frames) {

        capacity = frames;
        list = new DoublyLinkedList<int>();
    }

    ~LeastRecentlyUsed() {
        for (auto& pair : map) {
            delete pair.second;
        }

    }

    bool access(int page) {
        // Page hit
        if (map.count(page)) {
            Node<int>* node = map[page];
            list->remove_node(node);
            list->push_front(node);
            return true;
        }

        // Page miss
        if (map.size() == capacity) {
            int evicted = list->pop_back();
            if (evicted != -1) {
                map.erase(evicted);

            }
        }

        Node<int>* newNode = new Node<int>(page);
        list->push_front(newNode);
        map[page] = newNode;

        return false;
    }

    Node<int>* get_cache_head() const {
        return list->head_ptr();
    }
};
