#include <iostream>
#include <vector>
using namespace std;

class Max_Heap{

private:
    vector <int> heap;

    int parent(int i){
        return ((i-1) / 2);
    }

    int left(int i){
        return (i*2 + 1);
    }

    int right(int i){
        return (i*2 + 2);
    }

    void upHeapify(int i){

        while (i > 0 && heap[parent(i)] < heap[i]){
            swap(heap[i] ,heap[parent(i)]);
            i = parent(i);
        }
    }

    void downHeapify(int i){
        
        int largest = i;
        int l = left(i);
        int r = right(i);
        
        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;

        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i){
            swap(heap[i],heap[largest]);
            downHeapify(largest);
        }
    }

public:

    void insert(int x){
        heap.push_back(x);
        upHeapify(heap.size() - 1);
    }

    int popMax(){
        
        if (heap.empty()){
            cout << "Heap is empty!";
            return -1;
        }

        int maxVal = heap[0];
        swap(heap[0], heap.back());
        heap.pop_back();
        
        if (!heap.empty())
            downHeapify(0);

        return maxVal;
    }

    void printHeap() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }

};

int main() { //test
    Max_Heap h;

    h.insert(10);
    h.insert(40);
    h.insert(20);
    h.insert(50);
    h.insert(30);

    h.printHeap();   // مثلا: 50 40 20 10 30

    cout << h.popMax() << endl; // 50
    h.printHeap();

    return 0;
}