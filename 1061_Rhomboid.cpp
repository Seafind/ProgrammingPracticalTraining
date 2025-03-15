#include <iostream>
#include <string>
using namespace std;

void printDiamond(int n)
{
    for (int i = 0; i < n; ++i)
    {
        string spaces(n - i - 1, ' ');
        string stars(2 * i + 1, '*');
        cout << spaces << stars << endl;
    }

    for (int i = n - 2; i >= 0; --i)
    {
        string spaces(n - i - 1, ' ');
        string stars(2 * i + 1, '*');
        cout << spaces << stars << endl;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        printDiamond(n + 1);
    }
    return 0;
}