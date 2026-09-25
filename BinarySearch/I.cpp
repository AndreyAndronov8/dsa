#include <iostream>
#include <vector>

using namespace std;

void findCount (int num, vector<int>& array, int len)
{
    int left = -1;
    int right = len;

    int half;
    while (right - left > 1) {
        half = (right + left) / 2;
        if (array[half] >= num) {
            right = half;
        } else {
            left = half;
        }
    }

    int first = -1;
    if (right != len && array[right] == num) {
        first = right;
    } else {
        cout << "0 ";
        return;
    }

    left = -1;
    right = len;

    while (right - left > 1) {
        half = (right + left) / 2;
        if (array[half] > num) {
            right = half;
        } else {
            left = half;
        }
    }

    int last = left;

    cout << last - first + 1 << " ";
}


int main()
{
    int N;
    cin >> N;

    vector<int> allEls;
    int input;
    int j;
    for (int i = 0; i < N; i++) {
        cin >> input;
        allEls.push_back(input);
        
        j = allEls.size() - 1;
        if (j > 0) {
            while (j > 0 && allEls[j-1] > input) {
                allEls[j] = allEls[j-1];
                j--; 
            }
        }
        allEls[j] = input;
    }

    int M;
    cin >> M;

    vector<int> findingEls;
    for (int i = 0; i < M; i++) {
        cin >> input;
        findingEls.push_back(input);
    }

    for (int i = 0; i < M; i++) {
        findCount(findingEls[i], allEls, N);
    }
}