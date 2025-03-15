#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    cin >> n;
    int ques[n];
    for (int i = 0; i < n; i++) {
        int j = 0;
        cin >> ques[i];
        for (j = 0; j < m; j++)
        {
            if (arr[j] == ques[i]) {
                cout << "yes!" << endl;
                break;
            }
        }
        if (j == m) {
            cout << "no!" << endl;
        }
    }
    return 0;
}