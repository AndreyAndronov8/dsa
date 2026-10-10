#include <iostream>
#include <deque>
#include <algorithm> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    deque<int> dq;
    int num;
    for (int i = 0; i < K; i++) {
        cin >> num;
        dq.push_back(num);
    }

    int curMin = *min_element(dq.begin(), dq.end());
    cout << curMin << "\n";
    int front;
    for (int i = 0; i < N - K; i++) {
        cin >> num;
        dq.push_back(num);
        front = dq.front();
        dq.pop_front();

        curMin = min(num, curMin);

        if (front == curMin) {
            curMin = *min_element(dq.begin(), dq.end());
        }
        cout << curMin << "\n";
    }
}