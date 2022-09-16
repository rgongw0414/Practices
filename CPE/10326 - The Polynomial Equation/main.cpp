#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define eb emplace_back
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll N;
    while (cin >> N) {
        ll n = N; // n <= 50
        vector<ll> roots;
        roots.reserve(n);
        while (N--) {
            ll r;
            cin >> r;
            roots.eb(((-1)*r));
        }
        vector<ll> coef(n+1, 0);
        coef[1] = 1;
        coef[0] = roots[0];
        vector<ll> rc(2, 0);
        rc[1] = 1;
        for (int r = 1; r < n; r++) {
            cout << "r: " << r << endl;
            // i:   0, 1, 2, ...
            // ci: c0, c1, c2, ...
            // e.g. -1 + x => c0 = -1, c1 = 1
            rc[0] = roots[r];
            for (int j = 2; j <= n; j++) {
                vector<ll> coefTmp(n+1, 0);
                for (int k = 0; k <= j; k++) {
                    for (int i = 0; i <= 1; i++) {
                        coefTmp[i+k] += rc[i] * coef[k];
                    }
                }
                coef = coefTmp;
            }
        }
        reverse(coef.begin(), coef.end());
        for (auto &c: coef) {
            cout << c << " ";
        }
        cout << endl;
    }
}