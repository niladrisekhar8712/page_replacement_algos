#include <iostream>
#include <vector>
#include "pageReplacementAlgo.cpp"

using namespace std;

void printVector(const vector<int> &v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int frameSize, n;

    cout << "Enter number of frames: ";
    cin >> frameSize;

    cout << "Enter length of reference string: ";
    cin >> n;

    vector<int> referenceString(n);
    cout << "Enter the reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> referenceString[i];
    }

    cout << "\nGiven Reference String: ";
    printVector(referenceString);

    pageReplacementAlgo *p = new pageReplacementAlgo(frameSize, referenceString);

    cout << "\n--- Optimised Page Replacement ---\n";
    p->testOptimisedPage();

    cout << "\n--- FIFO Page Replacement ---\n";
    p->testFIFO();

    cout << "\n--- LRU Page Replacement ---\n";
    p->testLRU();

    cout << "\n--- LFU Page Replacement ---\n";
    p->testLFU();

    delete p;
    return 0;
}
