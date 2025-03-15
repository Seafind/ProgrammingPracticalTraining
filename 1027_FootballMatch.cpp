#include <iostream>

using namespace std;

typedef struct Team{
    int id;
    int score;
    int win;
    int lose;
    int tie;
} Team;

int main() {
    int n, m;
    while (true){
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        else {
            Team teams[n];
            for (int i = 0; i < n; i++){
                teams[i].id = i+1;
                teams[i].score = 0;
                teams[i].win = 0;
                teams[i].lose = 0;
                teams[i].tie = 0;
            }
            for (int i = 0; i < m; i++){
                int a, b, c;
                cin >> a >> b >> c;
                if (c == 1){
                    teams[a - 1].score += 3; 
                    teams[b - 1].score -= 1;
                    teams[a - 1].win++;
                    teams[b - 1].lose++;
                }
                else if (c == -1){
                    teams[a - 1].score -= 1;
                    teams[b - 1].score += 3;
                    teams[a - 1].lose++;
                    teams[b - 1].win++;
                }
                else if (c == 0){
                    teams[a - 1].score += 1;
                    teams[b - 1].score += 1;
                    teams[a - 1].tie++;
                    teams[b - 1].tie++;
                }
            }
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (teams[j].score < teams[j + 1].score)
                    {
                        swap(teams[j], teams[j + 1]);
                    }
                    else if (teams[j].score == teams[j + 1].score)
                    {
                        if (teams[j].win < teams[j + 1].win)
                        {
                            swap(teams[j], teams[j + 1]);
                        }
                        else if (teams[j].win == teams[j + 1].win)
                        {
                            if (teams[j].lose > teams[j + 1].lose)
                            {
                                swap(teams[j], teams[j + 1]);
                            }
                            else if (teams[j].lose == teams[j + 1].lose)
                            {
                                if (teams[j].id > teams[j + 1].id)
                                {
                                    swap(teams[j], teams[j + 1]);
                                }
                            }
                        }
                    }
                }
            }
            cout << teams[0].id;
            for (int i = 1; i < n; i++){
                cout << " " << teams[i].id;
            }
            cout << endl;
        }
    }
    return 0;
}
