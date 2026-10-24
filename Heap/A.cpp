#include <iostream>
#include <vector>

using namespace std;

class Heap 
{
public:
    vector<int> heap;
    int size = 0;

    Heap() {
        heap.push_back(0);
    }

    void siftUp(int i) 
    {
        while (i / 2 > 0 && heap[i] > heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    int indMaxChild(int i) 
    {
        if (i * 2 + 1 > size) {
            return i * 2;
        }
    
        if (heap[i * 2] > heap[i * 2 + 1]) {
            return i * 2;
        }
    
        return i * 2 + 1;
    }

    void siftDown(int i) 
    {
        while (i * 2 <= size) {
            int j = indMaxChild(i);
        
            if (heap[i] < heap[j]) {
                swap(heap[i], heap[j]);
            }
            i = j;
        }
    }

    void insert(int k) 
    {
        heap.push_back(k);
        size++;
        siftUp(size);
    }

    int extract() 
    {
        int removed = heap[1];
        heap[1] = heap[size];
        size--;
        heap.pop_back();
        siftDown(1);
        return removed;
    }
};

int main() 
{
    int n;
    cin >> n;

    Heap heap;
    int type;
    int k;

    for (int i = 0; i < n; i++) {
        cin >> type;
        if (type == 0) {
            cin >> k;
            heap.insert(k);
        } else if (type == 1) {
            cout << heap.extract() << "\n";
        }
    }
}