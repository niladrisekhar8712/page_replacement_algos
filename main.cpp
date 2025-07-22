#include <iostream>
#include <vector>
#include "pageReplacementAlgo.cpp"
using namespace std;
void printVector(vector<int> *v) {
    for (int i : *v) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    vector<int> referenceString = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = referenceString.size();
    printVector(&referenceString);
    pageReplacementAlgo *p = new pageReplacementAlgo(referenceString);
    int hits = p->fifo(10);
    cout << (double)hits/n << endl;
    return 0;
}

