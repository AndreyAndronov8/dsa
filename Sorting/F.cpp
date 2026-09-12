#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& vec, int low, int high) 
{
    int pivot = vec[(low + high) / 2];

    while (low <= high) {
        while (vec[low] < pivot) low++;
        while (vec[high] > pivot) high--;
        if (low <= high) swap(vec[low++], vec[high--]);
    }
    return low;
}

void QuickSort(vector<int>& vec, int low, int high) 
{
    if (low < high) {
        int pivotIndex = Partition(vec, low, high);

        QuickSort(vec, low, pivotIndex - 1);
        QuickSort(vec, pivotIndex, high);
    }
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

    QuickSort(vec, 0, len - 1);

    for (int i = 0; i < len; i++) {
        cout << vec[i] << " ";
    }
}