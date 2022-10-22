#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int m, n, c = 1;
    while (cin >> m >> n) {
        if (!m && !n) break;
        vector<vector<char>> f(m, vector<char>(n, '*'));
        string input;
        for (int i = 0; i < m; i++) {
            cin >> input;
            for (int j = 0; j < n; j++) {
                if (input[j] != '*') f[i][j] = '0';
            }
            input.clear();
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (f[i][j] == '*') {
                    if (i+1 < m && f[i+1][j] != '*') f[i+1][j]++;
                    if (i+1 < m && j-1 >= 0 && f[i+1][j-1] != '*') f[i+1][j-1]++;
                    if (j-1 >= 0 && f[i][j-1] != '*') f[i][j-1]++;
                    if (i-1 >= 0 && j-1 >= 0 && f[i-1][j-1] != '*') f[i-1][j-1]++;
                    if (i-1 >= 0 && f[i-1][j] != '*') f[i-1][j]++;
                    if (i-1 >= 0 && j+1 < n && f[i-1][j+1] != '*') f[i-1][j+1]++;
                    if (j+1 < n && f[i][j+1] != '*') f[i][j+1]++;
                    if (i+1 < m && j+1 < n && f[i+1][j+1] != '*') f[i+1][j+1]++;
                }
            }
        }
        if (c > 1) cout << endl;
        cout << "Field #" << c << ":\n";
        c++;
        for (auto &r: f) {
            for (auto &c: r) {
                cout << c;
            }
            cout << endl;
        }
    }
}