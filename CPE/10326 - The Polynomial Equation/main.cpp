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
        rc[0] = roots[1]; //******
        for (int j = 1; j < n; j++) { //******
            vector<ll> coefTmp(n+1, 0);
            for (int k = 0; k <= j; k++) {
                for (int i = 0; i <= 1; i++) {
                    coefTmp[i+k] += rc[i] * coef[k];
                }
            }
            coef = coefTmp;
            rc[0] = roots[j+1]; //******
        }
        reverse(coef.begin(), coef.end());
        auto iter = coef.begin();
        int nn = n;
        while (nn >= -1) {
            if (nn == n) {
                if (nn == 1) cout << "x";
                else cout << "x^" << nn;
            }
            else {
                if (nn > 0 && *iter != 0) {
                    if (*iter > 0) cout << " + ";
                    else if (*iter < 0) cout << " - ";
                    if (abs(*iter) != 1) cout << abs(*iter) << "x";
                    else cout << "x";
                    if (nn > 1) cout << "^" << nn;
                }
                if (nn == 0) {
                    if (*iter >= 0) cout << " + " << *iter;
                    else cout << " - " << *iter * (-1);
                    cout << " = 0\n";
                }
            }
            iter++;
            nn--;
        }
    }
}