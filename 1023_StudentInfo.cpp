#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct Student {
    unsigned long long id;
    char name[100];
    int score1;
    int score2;
    int score3;
    double AvgScore;
} Student;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        Student students[n];
        for (int j = 0; j < n; j++){
            cin >> students[j].id >> students[j].name >> students[j].score1 >> students[j].score2 >> students[j].score3;
            students[j].AvgScore = (students[j].score1 + students[j].score2 + students[j].score3) / 3.0;
        }
        for (int j = 0; j < n-1; j++){
            for (int k = j+1; k < n; k++){
                if (students[j].AvgScore < students[k].AvgScore){
                    swap(students[j], students[k]);
                }
                else if (students[j].AvgScore == students[k].AvgScore){
                    if (students[j].id > students[k].id){
                        swap(students[j], students[k]);
                    }
                }
            }
        }
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < n; j++)
        {
            cout << students[j].id << " " << students[j].name << " " << students[j].score1 << " " << students[j].score2 << " " << students[j].score3 << endl;
        }
    }
    return 0;
}