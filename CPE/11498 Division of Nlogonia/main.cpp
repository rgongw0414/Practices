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
    
    int k, m, n;
    while (cin >> k) {
        if (k == 0) break;
        cin >> m >> n; // division point coor.
        
        while (k--) {
            int x, y;
            cin >> x >> y;
            string ans;
            if (x == m || y == n) ans = "divisa\n";
            if (x > m && y > n) ans = "NE\n";
            if (x < m && y > n) ans = "NO\n";
            if (x < m && y < n) ans = "SO\n";
            if (x > m && y < n) ans = "SE\n";
            cout << ans;
        }
    }
}