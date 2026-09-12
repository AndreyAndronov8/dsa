#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& vec)
{
    for (int i = vec.size(); i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (vec[j] < vec[j+1]) {
                swap(vec[j], vec[j+1]);
            }
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

    BubbleSort(vec);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

}