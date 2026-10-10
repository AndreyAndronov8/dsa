#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string input;
    int a, b;
    stack<int> s;

    while (cin >> input) {
        if (input == "+" || input == "-" || input == "*") {
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if (input == "+") {
                s.push(a + b);
            } else if (input == "-") {
                s.push(a - b);
            } else if (input == "*") {
                s.push(a * b);
            }
        } else {
            s.push(stoi(input));
        }
    }

    cout << s.top();
}