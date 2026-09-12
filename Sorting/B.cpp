#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>& vec)
{
    for (int i = 1; i < vec.size(); i++) {
        int insertingNum = vec[i];
        int j = i;

        while (j > 0 && vec[j-1] > insertingNum) {
            vec[j] = vec[j-1];
            j--;
        }

        vec[j] = insertingNum;
    }
}

int main() 
{
    vector<int> vec;
    int num;

    while (cin >> num) {
        vec.push_back(num);
    }

    InsertionSort(vec);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}