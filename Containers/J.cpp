#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> Ks(N);
    vector<vector<double>> Priors(N);
    string input;
    double priority;
    for (int i = 0; i < N; i++) {
        cin >> Ks[i];
        for (int j = 0; j < Ks[i]; j++) {
            cin >> input;
            priority = stod(input);
            Priors[i].push_back(priority);
        }
    }

    int K;
    stack<double> buffer;
    double lastB = -1.0;

    bool flag = true;

    for (int i = 0; i < N; i++) {
        K = Ks[i];

        for (int j = 0; j < K; j++) {
            priority = Priors[i][j];
            
            if (buffer.empty() || buffer.top() >= priority) {
                buffer.push(priority);
            } else if (abs(lastB+1.0)<0.0001){
                lastB = buffer.top();
                buffer.pop();
                while (buffer.empty() == false && buffer.top() < priority) {
                    lastB = buffer.top();
                    buffer.pop();
                }
                buffer.push(priority);
            } else {
                while (buffer.empty() == false && buffer.top() < priority && buffer.top() >= lastB) {
                    lastB = buffer.top();
                    buffer.pop();
                }
                if (buffer.empty() || buffer.top() >= priority) {
                    buffer.push(priority);
                } else {
                    flag = false;
                    break;
                }
            }
        }

        while (buffer.empty() == false && buffer.top() >= lastB) {
            lastB = buffer.top();
            buffer.pop();
        }

        if (buffer.empty() == false) {
            flag = false;
        }

        if (flag) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }

        buffer = stack<double>();
        lastB = -1.0;
        flag = true;
    }
}