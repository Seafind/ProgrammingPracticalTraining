#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Offer {
    int id;
    int price;
} Offer;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> quantity(n);
    vector<Offer> offers(m);
    for (int i = 0; i < n; i++) {
        cin >> quantity[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> offers[i].id >> offers[i].price;
    }
    sort(offers.begin(), offers.end(), [](const Offer &a, const Offer &b)
        { return a.id < b.id || (a.id == b.id && a.price > b.price); });
    int ans = 0;
    vector<int> HeighestPrice(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (offers[j].id == i) {
                HeighestPrice[i-1] = offers[j].price;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans += quantity[i] * HeighestPrice[i];
    }
    cout << ans << endl;
    return 0;
}