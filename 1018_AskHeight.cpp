#include <iostream>
using namespace std;

typedef struct people {
    int height;
    int id;
} people;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        people mate[n];
        for (int i = 0; i < n; i++)
        {
            cin >> mate[i].height;
            mate[i].id = i + 1;
        }
        int ask[m];
        for (int i = 0; i < m; i++)
        {
            cin >> ask[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (mate[i].height < mate[j].height)
                {
                    swap(mate[i], mate[j]);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            cout << mate[ask[i] - 1].id << " ";
        }
        cout << endl;
    }
    return 0;
}