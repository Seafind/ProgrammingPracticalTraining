#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct StudyHall {
    string id;
    long long distance;
    int row;
    int column;
    char seat[20][20];
    bool is_available;
} StudyHall;

void is_valid(StudyHall& s) {
    for (int i = 1; i <= s.row; i++) {
        for (int j = 1; j <= s.column; j++) {
            if (s.seat[i-1][j] == '0' && s.seat[i][j-1] == '0' && s.seat[i][j+1] == '0' && s.seat[i][j] == '0') {
                s.is_available = true;
                return;
            }
        }
    }
    s.is_available = false;
    return;
}

int main (){
    int n;
    while(scanf ("%d", &n)!= EOF){
        StudyHall s[n];
        StudyHall result[n];
        int count = 0;
        for(int i = 0; i < n; i++){
            cin >> s[i].id >> s[i].distance >> s[i].row >> s[i].column;
            for(int j = 1; j <= s[i].row; j++){
                for(int k = 1; k <= s[i].column; k++){
                    cin >> s[i].seat[j][k];
                }
            }
            for (int j = 0; j <= s[i].row+1; j++){
                s[i].seat[0][j] = '0';
            }
            for (int j = 0; j <= s[i].column; j++){
                s[i].seat[j][0] = '0';
                s[i].seat[j][s[i].row + 1] = '0';
            }
            is_valid(s[i]);
            if (s[i].is_available){
                result[count++] = s[i];
            }
        }
        if (!count){
            cout << "Bad Luck,Rocker!" << endl;
            continue;
        }
        sort(result, result + count, [](const StudyHall& a, const StudyHall& b) {
            return a.distance < b.distance;
        });
        cout << result[0].id << endl;
    }
    return 0;
}

