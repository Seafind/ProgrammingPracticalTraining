#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string str[n];
    string result[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < n; i++) {
        if (str[i].substr(0, 7) == "http://"){
            result [count++]=str[i];
        }
    }
    sort (result, result + count);
    for (int i = 0; i < count; i++) {
        cout << result[i] << endl;
    }
    return 0;
}