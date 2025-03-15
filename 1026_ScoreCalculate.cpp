#include <iostream>
#include <cmath>

using namespace std;

int main (){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int score[120];
        int count = 0;
        while (true){
            int sc;
            cin >> sc;
            if (sc == -1) break;
            else score[count++] = sc;
        }
        int sum = 0;
        for (int j = 0; j < count; j++){
            sum += score[j];
        }
        double avg = (double)sum / count;
        
        int max = score[0];
        int min = score[0];
        for (int j = 1; j < count; j++){
            if (score[j] > max) max = score[j];
            if (score[j] < min) min = score[j];
        }
        cout << "case #" << i << ":\n"
            << floor(max) << endl
            << floor(min) << endl
            << floor(avg) << endl;
    }
}