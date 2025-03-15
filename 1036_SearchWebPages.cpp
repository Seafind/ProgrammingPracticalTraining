#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct Web
{
    string url;
    int v;
    int id;
} Web;

int main()
{
    int N;
    cin >> N;
    vector<Web> webs(N);
    for (int i = 0; i < N; i++)
    {
        cin >> webs[i].url >> webs[i].v;
        cin.ignore();
        webs[i].id = i + 1;
    }
    sort(webs.begin(), webs.end(), [](Web a, Web b)
        { return a.v > b.v || (a.v == b.v && a.id < b.id); });
    cout << webs[0].url << endl;
    for (int i = 1; i < N && webs[i].v == webs[0].v; i++)
    {
        cout << webs[i].url << endl;
    }
    return 0;
}