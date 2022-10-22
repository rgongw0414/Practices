#include <bits/stdc++.h>
#define ll unsigned long long
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
    
    ll low, high;
    while (cin >> low >> high && low>0 && high>0) {
        ll low_zeros = low / 5, high_zeros = high / 5;
        cout << high_zeros - low_zeros + 1 << endl;

        // set<ll> zeros;
        // ll n = 1, cnt = 0;
        // //*** more than 21! would cause overflow ***//
        // for (ll i = 2; i <= low; i++) {
        //     // count trailing zeros for low
        //     n *= i;
        //     if (n % 10 == 0) {
        //         n /= 10;
        //         cnt++;
        //     }
        // }
        // zeros.emplace(cnt);
        // for (ll i = low+1; i <= high; i++) {
        //     n *= i;
        //     if (n%10 == 0) {
        //         n /= 10;
        //         cnt++;
        //     }
        //     zeros.emplace(cnt);
        // }
        // cout << zeros.size() << endl;
    }
}