#include <iostream>
#include <vector>

using namespace std;

void CountSort(vector<int>& vec, int maxNum)
{
    vector<int> counter(maxNum + 1);

    for (int i = 0; i < vec.size(); i++) {
        counter[vec[i]]++;
    }

    int cur = 0;
    for (int i = 0; i < maxNum + 1; i++) {
        for (int j = 0; j < counter[i]; j++) {
            vec[cur++] = i;
        }
    }
}

int main() 
{
    vector<int> vec;
    int num;

    while (cin >> num) {
        vec.push_back(num);
    }

    CountSort(vec, 100);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

}