#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

vector<int> prices;
vector<int> weights; 

int solve(int n, int w) {
    vector<vector<int>> c(n+1, vector<int>(w+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (j - weights[i] < 0) {
                c[i][j] = c[i-1][j];
            }
            else {
                c[i][j] = max(
                    c[i-1][j], 
                    c[i-1][j-weights[i]] + prices[i]
                );
            }
        }
    }
    return c[n][w];
}

int solve2(int n, int w) {
    if (n == 0) 
        return 0;
    if (n > 0 && w < 0) 
        return solve2(n-1, w);
    
    return max(
        solve2(n-1, w), 
        solve2(n-1, w-weights[n]) + prices[n]
        );
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        prices.reserve(n+1); weights.reserve(n+1);
        prices.eb(0); weights.eb(0);
        int tmp = n;
        while (n--) {
            int p, w;
            cin >> p >> w;
            prices.eb(p); weights.eb(w);
        }
        
        n = tmp;
        int p;
        cin >> p;
        int ans = 0;
        while (p--) {
            int maxW;
            cin >> maxW;
            ans += solve2(n, maxW);
        }
        cout << ans << endl;
        prices.clear(); weights.clear();
    }
}