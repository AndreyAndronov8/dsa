#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double expression (int a, int b, int c, int d, double x)
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

void searchX(int a, int b, int c, int d)
{
    double left, right, x;
    x = 0.0;
    left = -1000000.0;
    right = 1000000.0;
    for (int i = 0; i < 100; i++) {
        x = (right + left) / 2;
        if (a > 0 && expression(a, b, c, d, x) > 0 || a < 0 && expression(a, b, c, d, x) < 0) {
            right = x;
        } else {
            left = x;
        }
    }
    cout <<  fixed << setprecision(4) << x;
}


int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    searchX(a, b, c, d);
}