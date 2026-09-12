#include <iostream>
#include <vector>
#include <string>

using namespace std;

string CreateMax(vector<string>& vec)
{
    for (int i = vec.size(); i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (vec[j] + vec[j+1] < vec[j+1] + vec[j]) {
                swap(vec[j], vec[j+1]);
            }
        }
    }
    string ans = "";
    for (int i = 0; i < vec.size(); i++) {
        ans += vec[i];
    }
    return ans;
}

int main()
{
    vector<string> vec;
    string str;
    while (cin >> str)
    {
        vec.push_back(str);
    }

    cout << CreateMax(vec);
}