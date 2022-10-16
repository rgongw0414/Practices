#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int e, f, c; // e, f < 1000
        cin >> e >> f >> c; // 1 < c < 2000
        e += f;
        int t = 0;
        while (e / c > 0) {
            t += e / c;
            e = e / c + e % c;
        }
        cout << t << endl;
    }
}