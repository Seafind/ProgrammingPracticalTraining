#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int totalsec;
    while (cin >> totalsec && totalsec != -1)
    {
        int hour, minute, second;
        hour = totalsec / 3600;
        totalsec %= 3600;
        minute = totalsec / 60;
        second = totalsec % 60;
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << endl;
    }
    return 0;
}