#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

typedef struct StringNumber {
    string str;
    int havenum;
    int num;
} StringNumber;

int HaveNumber (string s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            return 1;
        }
    }
    return 0;
}

int TheNumber (string s) {
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
        }
    }
    return ans;
}

int main() {
    vector<StringNumber> strnum(120);
    int i = 0;
    while (cin >> strnum[i].str) {
        strnum[i].havenum = HaveNumber(strnum[i].str);
        if (strnum[i].havenum) {
            strnum[i].num = TheNumber(strnum[i].str);
        }
        i++;
    }
    sort(strnum.begin(), strnum.begin() + i, [](const StringNumber &a, const StringNumber &b) {
        return a.havenum < b.havenum || (a.havenum == b.havenum && a.num < b.num);
    });
    for (int j = 0; j < i-1; j++) {
        for (int k = j+1; k < i; k++) {
            if (((strnum[j].havenum == 0 && strnum[k].havenum == 0) || (strnum[j].havenum != 0 && strnum[k].havenum != 0 && strnum[j].num == strnum[k].num))&& strcmp(strnum[j].str.c_str(), strnum[k].str.c_str()) > 0)
            {
                swap(strnum[j], strnum[k]);
            }
        }
    }
    for (int j = 0; j < i; j++) {
        cout << strnum[j].str << " ";
    }
    return 0;
}