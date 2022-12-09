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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j - weights[i] < 0) {
                c[i+1][j] = c[i][j];
            }
            else {
                c[i+1][j] = max(
                    c[i][j], 
                    c[i][j-weights[i]] + prices[i]
                );
            }
        }
    }
    return c[n][w];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        prices.reserve(n); weights.reserve(n);
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
            ans += solve(n, maxW);
        }
        cout << ans << endl;
        prices.clear(); weights.clear();
    }
}