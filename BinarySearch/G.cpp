#include <iostream>
#include <vector>

using namespace std;

/// 1 1 1 1 0 0 0 0

bool isThisLenPossible(int N, int K, vector<int>& lengths, int guess) 
{
    int counter = 0;
    for (int i = 0; i < N; i++) {
        counter += lengths[i] / guess;
        if (counter >= K) {
            return true;
        }
    }
    return false;
}

void findMaxLength(int N, int K, vector<int> lengths, int maxLen)
{
    int left = 0;
    int right = maxLen + 1;
    int guess;
    while (right - left > 1) {
        guess = (left + right) / 2;
        if (isThisLenPossible(N, K, lengths, guess) == true) {
            left = guess;
        } else {
            right = guess;
        }
    }
    cout << left;
}

int main()
{
    int N, K;
    cin >> N >> K;

    int input;
    vector<int> lengths;
    int maxLen = 0;
    int j;
    int insertingNum;
    for (int i = 0; i < N; i++) {
        cin >> input;

        if (input > maxLen) {
            maxLen = input;
        }

        lengths.push_back(input);
    }

    findMaxLength(N, K, lengths, maxLen);
}