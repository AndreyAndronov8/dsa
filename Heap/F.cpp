#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    priority_queue<int> starts, ends;
    int N, start, len;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> start;
        starts.push(-start);
        cin >> len;
        ends.push(-start - len);
    }

    int needed = 0;
    for (int i = 0; i < N; i++) {
        if (-starts.top() >= -ends.top()) {
            starts.pop();
            ends.pop();
        } else {
            starts.pop();
            needed++;
        }
    }

    cout << needed;
}