#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int n;
    cin >> n;
    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    sort(books.begin(), books.end(), [](int a, int b)
        { return a > b; });
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (i%3 == 2) continue;
        sum += books[i];
    }
    cout << sum << endl;
    return 0;
}