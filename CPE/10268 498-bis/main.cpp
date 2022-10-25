#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

void solve() {
    
}
 
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(NULL);
    
    ll x;
    while (cin >> x) {
        ll a;
        char c;
        vector<ll> as;
        while (scanf("%lld%c", &a, &c)) {
            as.eb(a);
            if (c != ' ') break;
        }
        ll sum = 0;
        ll n = as.size();
        // i: 0~n-2, j(x): n~1
        if (x != 0) {
            ll x1 = pow(x, n-1-1);
            for (ll i = 0, j = n-1; i < n-1; i++, j--) {
                sum += as[i]*j*x1;
                x1/=x;
            }
        }
        else sum = as[as.size()-2];
        cout << sum << endl;
    }
}