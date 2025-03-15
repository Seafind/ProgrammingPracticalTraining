#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

    using namespace std;

typedef struct Stu
{
    string id;
    int passnum;
    int pass[11];
    long long score = 0;
} Stu;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, M, G;
        cin >> N >> M >> G;
        long long weight[M];
        for (int j = 0; j < M; j++)
        {
            cin >> weight[j];
        }
        vector<Stu> stu(N);
        for (int j = 0; j < N; j++)
        {
            cin >> stu[j].id >> stu[j].passnum;
            for (int k = 0; k < stu[j].passnum; k++)
            {
                cin >> stu[j].pass[k];
            }
        }
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < stu[j].passnum; k++)
            {
                stu[j].score += weight[stu[j].pass[k] - 1];
            }
        }
        sort(stu.begin(), stu.end(), [](Stu a, Stu b)
            {
            if (a.score == b.score) {
                return a.id < b.id;
            }
            return a.score > b.score; });
        bool have = false;
        int count = 0;
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < N; j++)
        {
            if (stu[j].score >= G)
            {
                have = true;
                count++;
            }
        }
        if (have)
        {
            cout << count << endl;
            for (int j = 0; j < N; j++)
            {
                if (stu[j].score >= G)
                {
                    cout << stu[j].id << " " << stu[j].score << endl;
                }
            }
        }
        else
        {
            cout << "0" << endl;
        }
    }
    return 0;
}
