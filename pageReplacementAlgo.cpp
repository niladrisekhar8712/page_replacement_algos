#include <vector>
#include "FIFO.cpp"
#include "LeastRecentlyUsed.cpp"
#include "LeastFrequentlyUsed.cpp"
#include "OptimisedPageReplacement.cpp"
using namespace std;
class pageReplacementAlgo {
    private:
        int frames;
        vector<int> referenceString;

    public:
        pageReplacementAlgo(int frames, vector<int> referenceString) {
            this->frames = frames;
            this->referenceString = referenceString;
        }
    void print_cache(Node<int>* head) {
            unordered_set<Node<int>*> visited;
            while (head) {
                if (visited.count(head)) {
                    std::cout << "[Cycle Detected]" << std::endl;
                    break;
                }
                visited.insert(head);
                std::cout << head->data << " ";
                head = head->next;
            }
            cout << std::endl;
        }
        void testFIFO() {
            int pageHit = 0;
            FIFO *f = new FIFO(frames);

            for (int curr : referenceString) {
                if (f->fifo(curr)) pageHit++;
            }
            delete f;
            cout<< "Page Hits: " << pageHit << endl;
        }

    void testLRU() {
            LeastRecentlyUsed lru(frames);
            int pageHit = 0;
            cout << "Simulating LRU with " << frames <<" frames:\n";

            for (int page : referenceString) {
                bool hit = lru.access(page);
                if (hit) pageHit++;
                cout << "Page " << page << ": " << (hit ? "HIT" : "MISS") << " -> Cache: ";
                print_cache(lru.get_cache_head());
            }
            cout << "Page Hits: " << pageHit << endl;
        }


    void testLFU() {
            LeastFrequentlyUsed lfu(frames);
            int pageHit = 0;
            cout << "Simulating LFU with " << frames <<" frames:\n";

            for (int page : referenceString) {
                bool hit = lfu.access(page);
                if (hit) pageHit++;
                cout << "Page " << page << ": " << (hit ? "HIT" : "MISS") << " -> Cache: ";
                for (auto it : lfu.getKeyMap()) {
                    cout << it.first << " ";
                }
                cout << endl;
            }
            cout << "Page Hits: " << pageHit << endl;
        }



    void testOptimisedPage() {
            cout << "Simulating OptimalPageReplacement Algorithm with " << frames <<" frames:\n";

            int faults = optimalPageReplacement(referenceString, frames);
            cout << "Page Hits (Optimal): " << faults << endl;
        }

};