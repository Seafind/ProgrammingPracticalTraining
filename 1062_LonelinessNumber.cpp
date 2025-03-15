#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 1000000; i++) {
        bool isloneliness = true;
        for (int j = 1; j < i; j++) {
            if (j+j%10+(j/10)%10+(j/100)%10+(j/1000)%10+(j/10000)%10+(j/100000)%10 == i) {
                isloneliness = false;
                break;
            }
        }
        if (isloneliness) {
            cout << i << endl;
        }
    }
    return 0;
}