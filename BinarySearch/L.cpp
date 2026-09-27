#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// 0 0 0 0 1 1 1 1

bool isThisNumPossible(int N, int R, int C, vector<int>& heights, int guess) 
{
    int count = 0;
    int i = 0;
    while (i < N - C + 1) {
        if (heights[i + C - 1] - heights[i] <= guess) {
            count++;
            i+=C;
        } else {
            i++;
        }
    }
    return count >= R;
}

void findMinNumber(int N, int R, int C, vector<int>& heights)
{
    int left = -1;
    int right = heights[N-1] - heights[0] + 1;
    int guess;
    while (right - left > 1) {
        guess = (left + right) / 2;
        if (isThisNumPossible(N, R, C, heights, guess) == true) {
            right = guess;
        } else {
            left = guess;
        }
    }
    cout << right;
}

int main()
{
    int N, R, C;
    cin >> N >> R >> C;

    int input;
    vector<int> heights;
    for (int i = 0; i < N; i++) {
        cin >> input;
        heights.push_back(input);
    }

    sort(heights.begin(), heights.end());

    findMinNumber(N, R, C, heights);
}