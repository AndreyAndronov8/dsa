#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() 
{
    int N, num; 
    cin >> N;
    priority_queue<vector<int>> heap;
    for (int i = 1; i < N + 1; i++) {
        cin >> num;
        heap.push({-(max(1000-num, 1)), -num, -i});
    }

    int time = 0;
    bool flag = true;
    int curPos = 1;
    vector<int> next;
    int nextWait, nextNum, nextPos;

    while (flag) {
        next = heap.top();
        nextWait = -next[0];
        nextNum = -next[1];
        nextPos = -next[2];
        heap.pop();
        
        if (nextWait >= time + abs(nextPos - curPos)) {
            time = nextWait;
            curPos = nextPos;
            heap.push({-(time + max(1000-(nextNum + 1), 1)), -(nextNum + 1), -nextPos});
        } else {
            time = nextWait;
            flag = false;
        }
    }

    cout << time;
}