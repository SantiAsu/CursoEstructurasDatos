#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    //esta sera la funcion que mantendra la funcion maxheap
    void heapifyUp (int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index]>heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp (heap.size() - 1);
    }
    void printHeap() {
        for (int i: heap) {
            cout << i << " ";
        }
    }
};

int main() {
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(15);

    cout << "Heap actual: ";
    h.printHeap();

    return 0;
}