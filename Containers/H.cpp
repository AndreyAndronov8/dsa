#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() 
{
    string line;
    getline(cin, line);
    int N = stoi(line);

    deque<int> d1, d2;
    int num;
    vector<string> lines; 

    for (int i = 0; i < N; i++) {
        getline(cin, line);
        lines.push_back(line);
    }

    for (int i = 0; i < N; i++) {
        line = lines[i];
        if (line == "-") {
            cout << d1.front() << "\n";
            if (d1.size() == d2.size()) {
                d1.pop_front();
                d1.push_back(d2.front());
                d2.pop_front();
            } else {
                d1.pop_front();
            }
        } else {
            stringstream stream(line);
            stream >> line;
            stream >> num;
            if (line == "+") {
                d2.push_back(num);
                if ((d1.size() != d2.size())) {
                    d1.push_back(d2.front());
                    d2.pop_front();
                }
            } else {
                if (d1.size() == d2.size()) {
                    d1.push_back(num);
                } else {
                    d2.push_front(num);
                }
            }
        }
    }
}