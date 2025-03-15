#include <iostream>
#include <cstring>

using namespace std;

typedef struct strings {
    char str[220];
    char lowstr[220];
}strings;

void ToLower(char* str, char* lower){
    for(int i=0; i<(int)strlen(str); i++){
        lower[i] = tolower(str[i]);
    }
    lower[strlen(str)] = '\0';
}

int main (){
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cin.ignore();
        strings str[n];
        for (int j = 0; j < n; j++) {
            cin.getline(str[j].str, 220);
            ToLower(str[j].str, str[j].lowstr);
        }
        for (int j = 0; j < n-1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (strcmp(str[j].lowstr, str[k].lowstr) > 0) {
                    strings temp = str[j];
                    str[j] = str[k];
                    str[k] = temp;
                }
            }
        }
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << str[j].str << endl;
        }
    }
    return 0;
}