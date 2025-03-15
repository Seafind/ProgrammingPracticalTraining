#include <iostream>

using namespace std;

void FindSaddlePoint(int arr[5][5]);

int main (){
    int T;
    cin >> T;
    for (int i = 0; i < T;i++){
        int arr[5][5];
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                cin >> arr[j][k];
            }
        }
        cout << "case #" << i << ":" << endl;
        FindSaddlePoint(arr);
    }
    return 0;
}

void FindSaddlePoint(int arr[5][5]){
    int have = 0;
    for (int i = 0; i < 5; i++){
        int max = 0;
        int min = 101;
        int row = 0, col = 0;
        for (int j = 0; j < 5; j++){
            if (arr[i][j] > max){
                max = arr[i][j];
                row = i;
                col = j;
            }
        }
        for (int j = 0; j < 5; j++){
            if (arr[j][col] < min){
                min = arr[j][col];
            }
        }
        if (max == min){
            have = 1;
            cout << row << " " << col << endl;
        }
    }
    if (have == 0){
        cout << "-1 -1" << endl;
    }
}