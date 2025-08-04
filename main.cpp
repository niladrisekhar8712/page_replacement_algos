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
    int frameSize = 4;
    cout<< "Given Reference String: ";
    printVector(&referenceString);


    pageReplacementAlgo *p = new pageReplacementAlgo(frameSize, referenceString);




    p->testOptimisedPage();
    cout << endl;
    p->testFIFO();
    cout << endl;

    p->testLRU();

    return 0;
}


