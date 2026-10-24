#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() 
{
    string com;
    priority_queue<int> heap;
    int num;
    while (cin >> com)
    {
        if (com == "CLEAR") {
            heap = priority_queue<int>();
        } else if (com == "ADD") {
            cin >> num;
            heap.push(num);
        } else {
            if (heap.empty()) {
                cout << "CANNOT\n";
            } else {
                cout << heap.top() << "\n";
                heap.pop();
            }
        }
    }
}