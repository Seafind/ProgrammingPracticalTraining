#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0){
        cout << "1" << endl;
    }
    else if (n == 1){
        cout << "0" << endl;
    }
    else if (n % 2 == 0){
        for (int i = 2; i <= n; i += 2){
            cout << "8";
        }
        cout << endl;
    }
    else{
        cout << "4";
        for (int i = 3; i <= n; i += 2){
            cout << "8";
        }
        cout << endl;
    }
    return 0;
}