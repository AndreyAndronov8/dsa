#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

bool isLess(Point& a, Point& b) {
    return a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y;
}

int Partition(vector<Point>& vec, int low, int high)
{
    Point pivot = vec[(low + high) / 2];

    while (low <= high) {
        while (isLess(vec[low], pivot)) low++;
        while (isLess(pivot, vec[high])) high--;
        if (low <= high) swap(vec[low++], vec[high--]);
    }

    return low;
}


void QuickSort(vector<Point>& vec, int low, int high)
{
    if (low < high) {
        int pivotIndex = Partition(vec, low, high);

        QuickSort(vec, low, pivotIndex - 1);
        QuickSort(vec, pivotIndex, high);

    }
}


int main() 
{
    int len;
    cin >> len;

    vector<Point> points(len);

    for (int i = 0; i < len; i++) {
        cin >> points[i].x >> points[i].y;
    }

    QuickSort(points, 0, len - 1);

    for (int i = 0; i < len; i++) {
        cout << points[i].x << " " << points[i].y << "\n";
    }

    return 0;
}