#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>& fullVec, vector<int>& leftVec, int leftSize, vector<int>& rightVec, int rightSize) 
{
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (leftVec[i] <= rightVec[j]) {
            fullVec[k++] = leftVec[i++];
        } else {
            fullVec[k++] = rightVec[j++];
        }
    }

    while (i < leftSize) {
        fullVec[k++] = leftVec[i++];
    }
    while (j < rightSize) {
        fullVec[k++] = rightVec[j++];
    }
}

void MergeSort(vector<int>& vec, int len) 
{
    if (len < 2) return;

    int half = len / 2;

    vector<int> leftVec(half);
    for (int i = 0; i < half; i++) {
        leftVec[i] = vec[i];
    }

    vector<int> rightVec(len - half);
    for (int i = half; i < len; i++) {
        rightVec[i - half] = vec[i];
    }

    MergeSort(leftVec, half);
    MergeSort(rightVec, len - half);
    Merge(vec, leftVec, half, rightVec, len - half);
}


int main() 
{
    int len;
    cin >> len;

    vector<int> vec(len);
    int num;
    for (int i = 0; i < len; i++) {
        cin >> num;
        vec[i] = num;
    }

    MergeSort(vec, len);

    for (int i = 0; i < len; i++) {
        cout << vec[i] << " ";
    }
}