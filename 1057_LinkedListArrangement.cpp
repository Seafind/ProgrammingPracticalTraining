#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long n1, n2;
        cin >> n1 >> n2;

        long long node1[n1];
        for (long long j = 0; j < n1; j++) {
            cin >> node1[j];
        }

        unordered_set<long long> node2_set;
        for (long long j = 0; j < n2; j++) {
            long long val;
            cin >> val;
            node2_set.insert(val);
        }

        cout << "case #" << i << ":" << endl;
        bool has_output = false;

        for (long long j = 0; j < n1; j++) {
            if (node2_set.find(node1[j]) == node2_set.end()) {
                if (has_output) {
                    cout << " ";
                }
                cout << node1[j];
                has_output = true;
            }
        }
        cout << endl;
    }
    return 0;
}#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        long long n1, n2;
        cin >> n1 >> n2;

        long long node1[n1];
        for (long long j = 0; j < n1; j++) {
            cin >> node1[j];
        }

        unordered_set<long long> node2_set;
        for (long long j = 0; j < n2; j++) {
            long long val;
            cin >> val;
            node2_set.insert(val);
        }

        cout << "case #" << i << ":" << endl;
        bool has_output = false;

        for (long long j = 0; j < n1; j++) {
            if (node2_set.find(node1[j]) == node2_set.end()) {
                if (has_output) {
                    cout << " ";
                }
                cout << node1[j];
                has_output = true;
            }
        }
        cout << endl;
    }
    return 0;
}