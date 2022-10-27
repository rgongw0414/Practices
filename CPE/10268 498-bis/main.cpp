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
    while (scanf("%lld", &x) != EOF) {
        ll a;
        char c;
        vector<ll int> as;
        while (scanf("%lld%c", &a, &c)) {
            if (c != ' ') break;
            as.eb(a);
        }
        ll sum = 0, x1 = 1;
        for (ll i = as.size()-1, j = 1; i >= 0; i--, j++) {
            sum += as[i]*j*x1;
            x1*=x;
        }
        cout << sum << endl;
    }
}