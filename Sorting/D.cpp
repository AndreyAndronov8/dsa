#include <iostream>
#include <vector>

using namespace std;

int BubbleSort(vector<int>& vec, short len)
{
    int count = 0;
    for (int i = len; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                swap(vec[j], vec[j+1]);
                count++;
            }
        }
    }
    return count;
}

int main() 
{
    short len;
    cin >> len;

    vector<int> vec(len);
    int num;


    for (short i = 0; i < len; i++) {
        cin >> num;
        vec[i] = num;
    }

    cout << BubbleSort(vec, len);
}