#include <iostream>
#include <vector>

using namespace std;

void binarySearch(vector<int>& array, int arraySize, int num)
{
    int left, right;
    left = -1;
    right = arraySize;

    int middle;
    while (right-left > 1) {
        middle = (right + left) / 2;
        if (array[middle] > num) {
            right = middle;
        } else {
            left = middle;
        }
    }

    if (right == arraySize) {
        cout << array[left] << "\n";
    } else if (left == -1) {
        cout << array[right] << "\n";
    } else if (num - array[left] <= array[right] - num) {
        cout << array[left] << "\n";
    } else {
        cout << array[right] << "\n";
    }
}

int main()
{
    int N, K;
    cin >> N >> K;

    int input;
    vector<int> allEls, searchingEls;

    for (int i = 0; i < N; i++) {
        cin >> input;
        allEls.push_back(input);
    }

    for (int i = 0; i < K; i++) {
        cin >> input;
        binarySearch(allEls, N, input);
    }
}