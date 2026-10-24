#include <iostream>
#include <vector>
#include <string>

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
        while (i / 2 > 0 && heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    int indMinChild(int i) 
    {
        if (i * 2 + 1 > size) {
            return i * 2;
        }
    
        if (heap[i * 2] < heap[i * 2 + 1]) {
            return i * 2;
        }
    
        return i * 2 + 1;
    }

    void siftDown(int i) 
    {
        while (i * 2 <= size) {
            int j = indMinChild(i);
        
            if (heap[i] > heap[j]) {
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
        if (size == 0) {
            return -1;
        }
        int removed = heap[1];
        heap[1] = heap[size];
        size--;
        heap.pop_back();
        siftDown(1);
        return removed;
    }

    void clear() {
        size = 0;
        heap.clear();
        heap.push_back(0);
    }
};

int main() 
{
    string com;
    Heap heap;
    int num;
    while (cin >> com)
    {
        if (com == "CLEAR") {
            heap.clear();
        } else if (com == "ADD") {
            cin >> num;
            heap.insert(num);
        } else {
            num = heap.extract();
            if (num == -1) {
                cout << "CANNOT\n";
            } else {
                cout << num << "\n";
            }
        }
    }
}
