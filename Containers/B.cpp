#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    char ch;
    bool flag = true;
    while (cin >> ch) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (s.empty() == false &&
                  (ch == ')' && s.top() == '(' ||
                   ch == ']' && s.top() == '[' ||
                   ch == '}' && s.top() == '{')) {
            s.pop();
        } else {
            flag = false;
            break;
        }
    }

    if (flag == true && s.size() == 0) {
        cout << "yes";
    } else {
        cout << "no";
    }
}