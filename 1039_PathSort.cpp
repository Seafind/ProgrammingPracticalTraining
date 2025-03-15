#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Path {
    int begin;
    int end;
    int length;
} Path;

int main () {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int M, N;
        cin >> N >> M;
        vector<Path> paths(M);
        for (int i = 0; i < M; i++) {
            cin >> paths[i].begin >> paths[i].end >> paths[i].length;
        }
        sort(paths.begin(), paths.end(), [](const Path& a, const Path& b) {
            return a.length > b.length || (a.length == b.length && a.begin < b.begin )|| (a.length == b.length && a.begin == b.begin && a.end < b.end);
        });
        cout << "case #" << t << ":" << endl;
        for (int i = 0; i < M; i++) {
            cout << "(" <<paths[i].begin << "," << paths[i].end << "," << paths[i].length << ")"<< endl;
        }
    }
    return 0;
}