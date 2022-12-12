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
    
    ll coins[12] = {0, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    vector<ll> c(30001, 0);
    c[0] = 1;
    for (int i = 1; i < 12; i++) {
        for (int j = coins[i]; j <= 30000; j++) {
            c[j] = c[j] + c[j-coins[i]];
        }
    }
    int a, b;
    while (scanf("%d.%d", &a, &b) != EOF) {
        if (a == 0 && b == 0) break;
        printf("%3d.%02d%17lli\n", a, b, c[a*100+b]);
    }
}