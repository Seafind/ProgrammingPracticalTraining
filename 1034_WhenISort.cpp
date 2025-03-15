#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Data
{
    int number;
    int index1;
    int index2;
} Data;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        vector<Data> datas(N);
        for (int j = 0; j < N; j++)
        {
            cin >> datas[j].number;
            datas[j].index1 = j;
        }
        for (int j = N - 2; j > 0; j--)
        {
            for (int k = j - 1; k > 0; k--)
            {
                if (datas[j].number > datas[k].number)
                {
                    swap(datas[j], datas[k]);
                }
            }
        }
        for (int j = 0; j < N; j++)
        {
            datas[j].index2 = j;
        }
        for (int j = N - 2; j > 0; j--)
        {
            for (int k = j - 1; k > 0; k--)
            {
                if (datas[j].index1 > datas[k].index1)
                {
                    swap(datas[j], datas[k]);
                }
            }
        };
        for (int j = 0; j < N; j++)
        {
            cout << datas[j].index2 << " ";
        }
        cout << endl;
    }
    return 0;
}
