#include <iostream>
#include <cmath>

#define e 2.71828182845
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int n;
        cin >> n;
        double num[n];
        double result[n];
        int count = 0;
        for (int j = 0; j < n; j++){
            cin >> num[j];
        }
        double sum = 0;
        for (int j = 0; j < n; j++){
            sum += pow (e, num[j]);
        }
        for (int j = 0; j < n; j++){
            if (pow (e, num[j]) / sum >=0.5/n){
                result [count++] = num[j];
            }
        }
        for (int j = 0; j < count-1; j++){
            for (int k = j+1; k < count; k++){
                if (result[j] < result[k]){
                    swap (result[j], result[k]);
                }
            }
        }
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < count; j++){
            cout << result[j] << endl;
        }
    }
}