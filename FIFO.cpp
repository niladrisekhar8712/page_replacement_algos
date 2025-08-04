#include <queue>
#include <unordered_set>
using namespace std;
class FIFO {
    queue<int> q;
    unordered_set<int> set;
    int frames;
    public:
    FIFO(int frames) {
        this->frames = frames;
        set.clear();
        while (!q.empty()) {
            q.pop();
        }
    }
    void printQueue() {
        for (int page : set) {
            cout<<page<<" ";
        }
        cout<<endl;
    }

    ~FIFO() = default;

    bool fifo(int page) {
        if (set.contains(page)) {
            std::cout << "Page " << page << ": " << "HIT" << " -> Cache: ";
            printQueue();
            return true;
        }
        if (q.size() < frames) {
            q.push(page);
            set.insert(page);
        }
        else {
            int replacement = q.front();
            q.pop();
            set.erase(replacement);

            q.push(page);
            set.insert(page);
        }
        std::cout << "Page " << page << ": " << "MISS" << " -> Cache: ";
        printQueue();
        return false;
    }

};
