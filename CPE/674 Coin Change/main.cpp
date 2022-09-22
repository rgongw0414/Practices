#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;

int main() {
    // 50, 25, 10, 5, 1-cent
    int c[5] = {1, 5, 10, 25, 50};
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    const int MAX_VALUE = 7489;
    vector<int> ways(MAX_VALUE, 0);
    ways[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (int v = 1; v <= MAX_VALUE; v++) {
            if (v - c[i] >= 0) {
                ways[v] += ways[v - c[i]];
            }
        }
    }
    int n;
    while (cin >> n) {
        if (n <= 0) {
            cout << 1 << endl;
        }
        else {
            cout << ways[n] << endl;
        }
    }
}
