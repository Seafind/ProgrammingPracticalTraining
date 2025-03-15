#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef struct Number {
    long long num;
    int digit;
} Number;

int HighestDigit(long long num) {
    int digit = 0;
    num = abs(num);
    while (num > 0) {
        digit = num % 10;
        num /= 10;
    }
    return digit;
}

int main (){
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<Number> numbers(N);
        for (int i = 0; i < N; i++) {
            cin >> numbers[i].num;
            numbers[i].digit = HighestDigit(numbers[i].num);
        }
        sort(numbers.begin(), numbers.end(), [](const Number& a, const Number& b) {
            if (a.digit!= b.digit) {
                return a.digit > b.digit;
            }
            return a.num < b.num;
        });
        cout << "case #" << t << ":" << endl;
        for (int i = 0; i < N; i++) {
            cout << numbers[i].num << " ";
        }
        cout << endl;
    }
    return 0;
}