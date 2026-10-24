#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main() 
{
    priority_queue<int> heap;
    int N, num;
    cin >> N;
    double tax = 0.0;

    for (int i = 0; i < N; i++) {
        cin >> num;
        heap.push(-num);
    }

    while (heap.size() >= 2) {
        num = -heap.top();
        heap.pop();
        num += -heap.top();
        heap.pop();
        heap.push(-num);
        tax += num * 0.05;
    }

    cout << fixed << setprecision(2) << tax;
}