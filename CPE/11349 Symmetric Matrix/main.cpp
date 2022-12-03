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
    
    int t;
    cin >> t;
    int c = 1;
    while (t--) {
        cout << "Test #" << c++ << ": ";
        char tmp;
        int n;
        cin >> tmp >> tmp >> n;
        vector<vector<ll>> mat(n, vector<ll>(n, 0));
        bool sym = true;
        for (auto& row: mat) {
            for (auto& e: row) {
                ll v;
                cin >> v;
                e += v;
                if (v < 0) sym = false;
            }
        }
        if (!sym) {
            cout << "Non-symmetric.\n";
            continue;
        }
        for (int i = 0; i <= n/2; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != mat[n-1-i][n-1-j]) sym = false;
            }
        }
        if (sym) cout << "Symmetric.\n";
        else cout << "Non-symmetric.\n";
    }
}