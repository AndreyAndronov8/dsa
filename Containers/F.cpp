#include <iostream>
#include <deque>
#include <algorithm> 
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> nums;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        nums.push_back(num);
    }

    deque<int> dq;
    for (int i = 0; i < N; i++) {
        while (dq.empty() == false && i - dq.front() >= K) {
            dq.pop_front();
        }

        while (dq.empty() == false && nums[dq.back()] >= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if (i >= K - 1) {
            cout << nums[dq.front()] << "\n";
        }
    }
}