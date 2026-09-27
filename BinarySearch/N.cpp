#include <iostream>

using namespace std;

// 0 0 0 0 1 1 1 1

bool isAllChoped(long long dmitSpeed, long long dmitPass, long long fedSpeed, long long fedPass, long long trees, long long guess)
{
    return (__int128)dmitSpeed * (guess - guess / dmitPass) + (__int128)fedSpeed * (guess - guess / fedPass)  >= trees;
}

void countDays(long long dmitSpeed, long long dmitPass, long long fedSpeed, long long fedPass, long long trees)
{
    long long left = 0;
    long long right = trees / min(dmitSpeed, fedSpeed) * 2 + 1;
    long long guess;
    while (right - left > 1) {
        guess = left + (right - left) / 2;
        if (isAllChoped(dmitSpeed, dmitPass, fedSpeed, fedPass, trees, guess) == true) {
            right = guess;
        } else {
            left = guess;
        }
    }
    cout << right;
}

int main()
{
    long long A, K, B, M, X;
    cin >> A >> K >> B >> M >> X;

    countDays(A, K, B, M, X);
}