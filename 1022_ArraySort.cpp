#include <iostream>

using namespace std;

typedef struct Array {
    int number;
    int times;
} Array;

int main (){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int N;
        cin >> N;
        int arr[N];
        Array times[N];
        for (int j = 0; j < N; j++){
            cin >> arr[j];
        }
        for (int j = 0; j < N-1; j++){
            for (int k = j+1; k < N; k++){
                if (arr[j] > arr[k]){
                    int temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                }
            }
        }
        int count = 1;
        times[0].number = arr[0];
        times[0].times = 1;
        for (int j = 1; j < N; j++){
            if (arr[j] == arr[j-1]){
                times[count-1].times++;
            }
            else{
                times[count].number = arr[j];
                times[count].times = 1;
                count++;
            }
        }
        for (int j = 0; j < count-1; j++){
            for (int k = j+1; k < count; k++){
                if (times[j].times < times[k].times){
                    Array temp = times[j];
                    times[j] = times[k];
                    times[k] = temp;
                }
                else if (times[j].times == times[k].times){
                    if (times[j].number > times[k].number){
                        Array temp = times[j];
                        times[j] = times[k];
                        times[k] = temp;   
                    }
                }
            }
        }
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < times[j].times; k++)
            {
                cout << times[j].number << " ";
            }
        }
        cout << endl;
    }
    return 0;
}