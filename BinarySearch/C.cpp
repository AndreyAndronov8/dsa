#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double expression (double x)
{
    return pow(x, 2) + sqrt(x);
}

void searchX(double C)
{
    double left, right, x;
    x = 0.0;
    left = 0.0;
    right = sqrt(C);
    for (int i = 0; i < 100; i++) {
        x = (right + left) / 2;
        if (expression(x) > C) {
            right = x;
        } else {
            left = x;
        }
    }
    cout <<  fixed << setprecision(6) << x;
}


int main()
{
    double C;
    cin >> C;

    searchX(C);
}