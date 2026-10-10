#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int num;
    cin >> num;

    stack<vector<int>> st;
    st.push({num, 1});

    int destroyed = 0;

    int deleating;

    for (int i = 1; i < N; i++) {
        cin >> num;
        if (st.top()[0] == num) {
            st.push({num, st.top()[1] + 1});
        } else if (st.top()[1] >= 3) {
            deleating = st.top()[0];
            while (st.empty() == false && st.top()[0] == deleating) {
                st.pop();
                destroyed++;
            }
            if (st.empty() || st.top()[0] != num) {
                st.push({num, 1});
            } else {
                st.push({num, st.top()[1] + 1});
            }
        } else {
            st.push({num, 1});
        }
    }

    if (st.empty() == false && st.top()[1] >= 3) {
        deleating = st.top()[0];
        while (st.empty() == false && st.top()[0] == deleating) {
            st.pop();
            destroyed++;
        }
    }
    
    cout << destroyed;
}