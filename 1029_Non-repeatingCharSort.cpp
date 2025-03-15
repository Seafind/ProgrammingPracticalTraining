#include <iostream> 
#include <cstring> 
#include <algorithm> 

using namespace std;

typedef struct Strings {
    char str[30];
    char sortstr[30];
    int NonRepChar;
} Strings;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        int n;
        cin >> n;
        Strings strings[n];
        for (int j = 0; j < n;j++) {
            cin >> strings[j].str;
            strings[j].NonRepChar = 0;
            strcpy(strings[j].sortstr, strings[j].str);
        }
        for (int j = 0; j < n; j++) {
            sort(strings[j].sortstr, strings[j].sortstr + strlen(strings[j].sortstr));
            for (int k = 0; k < (int)strlen(strings[j].sortstr); k++) {
                if (strings[j].sortstr[k] != strings[j].sortstr[k + 1]) {
                    strings[j].NonRepChar ++;
                }
            }
        }
        for (int i = 0; i < n-1;i++){
            for (int j = i+1; j < n; j++){
                if (strings[i].NonRepChar < strings[j].NonRepChar) {
                    swap (strings[i], strings[j]);
                }
                else if (strings[i].NonRepChar == strings[j].NonRepChar) {
                    if (strcmp(strings[i].str, strings[j].str) > 0) {
                        swap(strings[i], strings[j]);
                    }
                }
            }
        }
        cout << "case #" << i << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << strings[j].str << endl;
        }
    }
    return 0;
}