#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

#define PI 3.14159265358979

typedef struct Point {
    double x, y;
    double r, theta;
} Point;

class PolarOrdering {
    public:
        PolarOrdering();
        void Initalize(int n);
        void DataInput(double x, double y, int i);
        void CalculateTheta(int i);
        void CalculateR(int i);
        void Sort();
        void Print();
    private:
        vector<Point> points;
};

PolarOrdering::PolarOrdering() {
    points.resize(0);
}

void PolarOrdering::Initalize(int n) {
    points.resize(n);
}

void PolarOrdering::DataInput(double x, double y, int i) {
    points[i].x = x;
    points[i].y = y;
}

void PolarOrdering::CalculateTheta(int i)
{
    points[i].theta = atan2(points[i].y, points[i].x);
    if (points[i].theta < 0)
    {
        points[i].theta += 2 * PI; 
    }
}

void PolarOrdering::CalculateR(int i) {
    points[i].r = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
}

void PolarOrdering::Sort() {
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return (a.theta < b.theta || (a.theta == b.theta && a.r > b.r));}); 
}

void PolarOrdering::Print() {
    for (size_t i = 0; i < points.size(); i++) {
        cout << "(" << fixed << setprecision(4) 
        << points[i].r << "," << fixed << setprecision(4) << points[i].theta << ")" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        PolarOrdering po;
        po.Initalize(n);
        for (int j = 0; j < n; j++) {
            double x, y;
            cin >> x >> y;
            po.DataInput(x, y, j);
        }
        for (int j = 0; j < n; j++) {
            po.CalculateTheta(j);
            po.CalculateR(j);
        }
        po.Sort();
        cout << "case #" << i << ":" << endl;
        po.Print();
    }
    return 0;
}