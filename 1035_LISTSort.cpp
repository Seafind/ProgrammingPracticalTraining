#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

typedef struct LIST {
    string date;
    string time;
    long long volume;
    string name;
} LIST;

int main() {
    int n;
    bool isfirst = true;
    while (cin >> n && n) {
        if (!isfirst) {
            cout << endl;
        }
        vector <LIST> lst;
        for (int i = 0; i < n; i++) {
            string date, time, name;
            long long volume;
            cin >> date >> time >> volume >> name;
            lst.push_back({date, time, volume, name});
        }
        cin.ignore();
        string mode;
        getline(cin, mode);
        if (mode == "LIST /TIME") {
            sort (lst.begin(), lst.end(), [](LIST a, LIST b) {
                return a.date < b.date || (a.date == b.date && a.time < b.time || (a.date == b.date && a.time == b.time && a.name < b.name));
            });
        }
        else if (mode == "LIST /NAME") {
            sort (lst.begin(), lst.end(), [](LIST a, LIST b) {
                return a.name < b.name;
            });
        }
        else if (mode == "LIST /SIZE") {
            sort (lst.begin(), lst.end(), [](LIST a, LIST b) {
                return a.volume < b.volume || (a.volume == b.volume && a.name < b.name);
            });
        }
        for (int i = 0; i < n; i++) {
            cout << lst[i].date << " " << lst[i].time << " "
            << right << setw(16) << lst[i].volume << " " << lst[i].name << endl;
        }
        isfirst = false;
    }
    return 0;
}
