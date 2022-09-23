#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

void solve() {
    
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    ll v1, d1, v2, d2;
    ll c = 1;
    while (cin >> v1 >> d1 >> v2 >> d2) {
        if (!v1 && !d1 && !v2 && !d2) break;
        // v: miles per hour, d: miles
        string ans;
        ll t1 = d1*v2, t2 = d2*v1; // 通分後比較分子的大小（省去浮點數與整數type不同的麻煩）
        if (t1 < t2) ans = "You owe me a beer!";
        else ans = "No beer for the captain.";
        cout << "Case #" << c << ": " << ans << endl;
        ll a = d1*v2 + v1*d2, b = v1 * v2 * 2; // 通分
        ll abgcd = __gcd(a, b); // 將分式化為最簡式
        if (a % b == 0) cout << "Avg. arrival time: " << a/b << endl;
        else cout << "Avg. arrival time: " << a/abgcd << "/" << b/abgcd << endl;
        c++;
    }
}