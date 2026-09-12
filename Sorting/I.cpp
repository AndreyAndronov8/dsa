#include <iostream>
#include <vector>
#include <string>

using namespace std;

string IsAnagramm(string& str1, string& str2)
{
    if (str1.length() != str2.length())
    {
        return "NO";
    }

    vector<short> counter1(36);
    vector<short> counter2(36);

    for (short i = 0; i < str1.length(); ++i) {
        char c = str1[i];
        if (c >= 'a' && c <= 'z') {
            counter1[c - 'a']++;
        } else if (c >= '0' && c <= '9') {
            counter1[c - '0' + 26]++;
        }
    }

    for (short i = 0; i < str2.length(); ++i) {
        char c = str2[i];
        if (c >= 'a' && c <= 'z') {
            counter2[c - 'a']++;
        } else if (c >= '0' && c <= '9') {
            counter2[c - '0' + 26]++;
        }
    }

    for (short i = 0; i < 36; i++) {
        if (counter1[i] != counter2[i]) {
            return "NO";
        }
    }

    return "YES";
}


int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    cout << IsAnagramm(str1, str2);
}