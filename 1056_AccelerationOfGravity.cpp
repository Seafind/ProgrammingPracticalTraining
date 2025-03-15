#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define G 9.8

int main() {
    int floor;
    cin >> floor;
    double height;
    if (floor == 1 || floor == 2) {
        height = 5 * (floor - 1) + 1.75;
    } 
    else {
        height = 3 * (floor - 3) + 11.75;
    }
    double time = sqrt(2 * height / G);
    cout << fixed << setprecision(3) << time << endl;
    return 0;
}