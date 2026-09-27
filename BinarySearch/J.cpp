#include <iostream>

using namespace std;

// 1 1 1 1 0 0 0 0

bool isThisWidthPos(long long count, long long  a, long long  b, long long  w, long long  h, long long  guess)
{
    long long variant1 = (w / (a + 2*guess)) * (h / (b + 2*guess));
    long long variant2 = (w / (b + 2*guess)) * (h / (a + 2*guess));
    
    return max(variant1, variant2) >= count;
}

void findMaxWidth(long long count, long long a, long long b, long long w, long long h)
{
    long long left = -1;
    long long right = max(w, h);
    long long guess;

    while (right - left > 1) {
        guess = left + (right - left) / 2;
        if (isThisWidthPos(count, a, b, w, h, guess) == true) {
            left = guess;
        } else {
            right = guess;
        }
    }
    cout << left;

}

int main()
{
    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    
    findMaxWidth(n, a, b, w, h);
}