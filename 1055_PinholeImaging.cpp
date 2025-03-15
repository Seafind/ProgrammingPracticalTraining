#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A, B, H;
        cin >> A >> B >> H;
        double ans = (double)H / (double)A * B;
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}