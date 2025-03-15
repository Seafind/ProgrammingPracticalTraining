#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef struct MayaDate {
    int day;
    string month;
    int month_num;
    int year;
} MayaDate;

void MonthToNum(string month, int& month_num) {
    static const map<string, int> month_map = {
        {"pop", 1}, {"no", 2}, {"zip", 3}, {"zotz", 4}, {"tzec", 5}, {"xul", 6}, {"yoxkin", 7}, {"mol", 8}, {"chen", 9}, {"yax", 10}, {"zac", 11}, {"ceh", 12}, {"mac", 13}, {"kankin", 14}, {"muan", 15}, {"pax", 16}, {"koyab", 17}, {"cumhu", 18}};

    auto it = month_map.find(month);
    if (it != month_map.end()){
        month_num = it->second;
    }
    else{
        month_num = 19; 
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<MayaDate> dates(N);
        for (int j = 0; j < N; j++) {
            char c = '.';
            cin >> dates[j].day >> c >> dates[j].month >> dates[j].year;
            cin.ignore();
            MonthToNum(dates[j].month, dates[j].month_num);
        }
        sort(dates.begin(), dates.end(), [](MayaDate a, MayaDate b) {return a.year < b.year || (a.year == b.year && a.month_num < b.month_num) || (a.year == b.year && a.month_num == b.month_num && a.day < b.day);});
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < N; j++) {
            cout << dates[j].day << ". " << dates[j].month << " " << dates[j].year << endl;
        }
    }
    return 0;
}