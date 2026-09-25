#include <iostream>
#include <vector>

using namespace std;

bool isDistancePossible(int stallNum, int cowNum, vector<int>& stallCoords, int guess)
{
    int cowsLeft = cowNum - 1;
    int lastTaken = stallCoords[0];
    for (int i = 1; i < stallNum; i++) {
        if (stallCoords[i] - lastTaken >= guess) {
            lastTaken = stallCoords[i];
            cowsLeft--;
            if (cowsLeft == 0) {
                return true;
            }
        }
    }
    return false;
}


void findMinDistance(int stallNum, int cowNum, vector<int>& stallCoords)
{
    int left = 1;
    int right = stallCoords[stallNum-1] - stallCoords[0];

    if (isDistancePossible(stallNum, cowNum, stallCoords, right) == true) {
        cout << right;
        return;
    }

    int guess;
    while (right - left > 1) {
        guess = (left + right) / 2;
        if (isDistancePossible(stallNum, cowNum, stallCoords, guess) == true) {
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

    vector<int> coords;
    int coord;
    for (int i = 0; i < N; i++) {
        cin >> coord;
        coords.push_back(coord);
    }

    findMinDistance(N, K, coords);
}