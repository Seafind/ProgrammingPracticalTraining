#include <iostream>
#include <cmath>

using namespace std;

int main() {
    bool have = false;
    for (int i = 1000; i <= 9999; i++) {
        int a = i / 1000;
        int b = (i % 1000) / 100;
        int c = (i % 100) / 10;
        int d = i % 10;
        if (pow(a, 4) + pow(b, 4) + pow(c, 4) + pow(d, 4) == i) {
            cout << i << endl;
            have = true;
        }
    }
    if (!have) {
        cout << "no answer" << endl;
    }
    return 0;    
}