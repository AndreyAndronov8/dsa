#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> d1, d2;
    int num;
    for (int i = 0; i < 5; i++) {
        cin >> num;
        d1.push_back(num);
    }
    for (int i = 0; i < 5; i++) {
        cin >> num;
        d2.push_back(num);
    }

    int steps = 0;
    while (!d1.empty() && !d2.empty() && steps <= 1000000) {
        if ((d1.front() == 0 && d2.front() == 9) || (d1.front() > d2.front() && !(d1.front() == 9 && d2.front() == 0))) {
            d1.push_back(d1.front());
            d1.pop_front();
            d1.push_back(d2.front());
            d2.pop_front();
        } else {
            d2.push_back(d1.front());
            d1.pop_front();
            d2.push_back(d2.front());
            d2.pop_front();
        }
        steps++;
    }

    if (d1.empty()) {
        cout << "second " << steps;
    } else if (d2.empty()) {
        cout << "first " << steps;
    } else {
        cout << "botva";
    }
}