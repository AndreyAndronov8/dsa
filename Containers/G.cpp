#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int input;
    int wait = 1;
    stack<int> st;
    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input == wait) {
            wait++;
        } else {
            st.push(input);
        }

        while (st.empty() == false && st.top() == wait) {
            st.pop();
            wait++;
        }
    }

    if (st.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}