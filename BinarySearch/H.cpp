#include <iostream>

using namespace std;

// 0 0 0 0 1 1 1 1

bool isThisSizePossible(long long w, long long h, long long n, long long guess)
{
    if ((guess / w) * (guess / h) >= n) {
        return true;
    }
    return false;
}

void findMinSize(long long w, long long h, long long n) 
{
    long long left = max(w, h) - 1;
    long long right = max(w, h) * n + 1;

    long guess;
    while (right - left > 1) {
        guess = (right + left) / 2;

        if (isThisSizePossible(w, h, n, guess) == true) {
            right = guess;
        } else {
            left = guess;
        }
    }
    cout << right;
}

int main()
{
    long long w, h, n;
    cin >> w >> h >> n;
    
    findMinSize(w, h, n);
}