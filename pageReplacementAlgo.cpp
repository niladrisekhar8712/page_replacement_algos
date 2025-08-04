#include <vector>
#include "FIFO.cpp"
#include "LeastRecentlyUsed.cpp"
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
            std::unordered_set<Node<int>*> visited;
            while (head) {
                if (visited.count(head)) {
                    std::cout << "[Cycle Detected]" << std::endl;
                    break;
                }
                visited.insert(head);
                std::cout << head->data << " ";
                head = head->next;
            }
            std::cout << std::endl;
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
            std::cout << "Simulating LRU with 3 frames:\n";

            for (int page : referenceString) {
                bool hit = lru.access(page);
                if (hit) pageHit++;
                std::cout << "Page " << page << ": " << (hit ? "HIT" : "MISS") << " -> Cache: ";
                print_cache(lru.get_cache_head());
            }
            cout << "Page Hits: " << pageHit << endl;
        }
    void testOptimisedPage() {
            int faults = optimalPageReplacement(referenceString, frames);
            cout << "Page Hits (Optimal): " << faults << endl;
        }

};