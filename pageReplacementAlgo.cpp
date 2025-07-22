#include <vector>
#include<queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class pageReplacementAlgo {
    private:
        vector<int> referenceString;
    public:
        pageReplacementAlgo(vector<int> referenceString) {
            this->referenceString = referenceString;
        }

        int fifo(int frames) {
            int pageHit = 0;
            queue<int> q;
            unordered_set<int> set;

            for (int curr : referenceString) {
                if (set.contains(curr)) {
                    pageHit++;
                    continue;
                }
                if (q.size() < frames) {
                    q.push(curr);
                    set.insert(curr);
                }
                else {
                    int replacement = q.front();
                    q.pop();
                    set.erase(replacement);

                    q.push(curr);
                    set.insert(curr);
                }
            }
            return pageHit;
        }
    // optimal
    // LRU
};