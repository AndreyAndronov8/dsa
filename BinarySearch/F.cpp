#include <iostream>

using namespace std;

// 0 0 0 0 1 1 1 1

bool isThisTimePossible(int required, int printTime1, int printTime2, int guess)
{
     if (((guess - min(printTime1, printTime2)) / printTime1) + ((guess - min(printTime1, printTime2)) / printTime2) + 1 >= required) {
        return true;
     }
     return false;
}

void findMinTime(int required, int printTime1, int printTime2) 
{
    int left = min(printTime1, printTime2) - 1;
    int right = required * max(printTime1, printTime2) + 1;

    int guess;
    while (right - left > 1) {
        guess = (right + left) / 2;

        if (isThisTimePossible(required, printTime1, printTime2, guess) == true) {
            right = guess;
        } else {
            left = guess;
        }
    }
    cout << right;
}

int main()
{
    int N, x, y;
    cin >> N >> x >> y;
    
    findMinTime(N, x, y);
}