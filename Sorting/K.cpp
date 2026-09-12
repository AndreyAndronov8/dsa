#include <iostream>
#include <vector>

using namespace std;

// 1
// 1 2
// 1 3 2
// 1 4 2 3
// 1 4 5 3 2
// 1 4 6 3 2 5
// 1 4 6 7 2 5 3
// 1 4 6 8 2 5 3 7
// 1 4 6 8 9 5 3 7 2

int main()
{
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        vec[i] = i + 1;
    }

    for (int i = 2; i < N; i++) {
        swap(vec[i], vec[i / 2]);
    }

    for (int i = 0; i < N; i++) {
        cout << vec[i] << " ";
    }
}