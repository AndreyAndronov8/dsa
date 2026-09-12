#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(vector<int>& vec)
{
    int maxNumInd = 0;
    for (int i = 0; i < vec.size(); i++) {
        maxNumInd = i;
        for (int j = i; j < vec.size(); j++) {
            if (vec[maxNumInd] < vec[j]) {
                maxNumInd = j;
            }
        }
        swap(vec[i], vec[maxNumInd]);
    }   
}

int main() 
{
    vector<int> vec;
    int num;

    while (cin >> num) {
        vec.push_back(num);
    }

    SelectionSort(vec);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

}