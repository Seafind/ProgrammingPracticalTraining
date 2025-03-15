#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

void Words(const string &text, set<string> &words)
{
    string word;
    for (char ch : text){
        if (isalpha(ch)){ 
            word += ch;
        }
        else if (!word.empty()){                       
            words.insert(word); 
            word.clear();     
        }
    }
    if (!word.empty()){ 
        words.insert(word);
    }
}

int main()
{
    int T;
    cin >> T;     
    cin.ignore(); 
    for (int i = 0; i < T; ++i)
    {
        string text;
        getline(cin, text);
        set<string> words; 
        Words(text, words);
        cout << "case #" << i << ":" << endl;
        auto it = words.begin();
        if (it != words.end()){
            cout << *it++; 
        }
        while (it != words.end()){
            cout << " " << *it++; 
        }
        cout << endl;
    }
    return 0;
}