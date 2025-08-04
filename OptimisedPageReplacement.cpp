#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void printMemory(unordered_set<int> memory) {
    for (int page : memory) {
        cout<<page<<" ";
    }
    cout<<endl;
}
int optimalPageReplacement(vector<int> pages, int capacity) {
    unordered_set<int> memory;
    int pageHits = 0;

    for (int i = 0; i < pages.size(); i++) {
        int current = pages[i];

        if (memory.contains(current)) {
            pageHits++;
            std::cout << "Page " << current << ": " << "HIT" << " -> Cache: ";
            printMemory(memory);
            continue;
        }


        if (memory.size() < capacity) {
            memory.insert(current);
        } else {
            int indexToRemove = -1;
            int farthest = i + 1;
            int pageToRemove;

            for (int page : memory) {
                int j;
                for (j = i + 1; j < pages.size(); ++j) {
                    if (pages[j] == page) break;
                }

                if (j == pages.size()) {
                    pageToRemove = page;
                    break;
                }

                if (j > farthest) {
                    farthest = j;
                    pageToRemove = page;
                }
            }

            memory.erase(pageToRemove);
            memory.insert(current);

            std::cout << "Page " << current << ": " << "MISS" << " -> Cache: ";
            printMemory(memory);
        }
    }

    return pageHits;
}