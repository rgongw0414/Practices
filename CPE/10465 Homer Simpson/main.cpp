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
    
    int m, n, t;
    while (cin >> m >> n >> t) {
        vector<int> c(t+1, -1);
        c[0] = 0;
        for (int j = m; j <= t; j++) {
            if (c[j-m] != -1)
                c[j] = max(c[j], c[j-m] + 1);
        }
        for (int j = n; j <= t; j++) {
            if (c[j-n] != -1)
                c[j] = max(c[j], c[j-n] + 1);
        }

        for (int i = t; i >= 0; i--) {
            if (c[i] != -1) {
                cout << c[i];
                if (i < t) cout << " " << t-i;
                break;
            }
        }
        cout << endl;
    }
}