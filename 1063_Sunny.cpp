#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        char alice[120];
        cin >> alice;
        int len = strlen(alice);
        for (int j = 0; j < len; j++)
        {
            cout << setw(2) << setfill('0') << alice[j] - 'a' + 1;
        }
        cout << endl;
    }
    return 0;
}