#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long FindLowestPrice(vector<int>& distances, vector<int>& costs)
{
    long long price = 0;
    sort(begin(distances), end(distances));
    sort(begin(costs), end(costs), greater<int>());

    for (int i = 0; i < costs.size(); i++) {
        price += static_cast<long long>(distances[i])*costs[i];
    }

    return price;
}

int main()
{
    int num;

    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }

    int len = nums.size() / 2;
    vector<int> distances(len);
    vector<int> costs(len);
    for (int i = 0; i < len; i++) {
        distances[i] = nums[i];
        costs[i] = nums[i + len];
    }

    cout << FindLowestPrice(distances, costs);
}