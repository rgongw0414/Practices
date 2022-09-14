#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;

int main() {
    // 50, 25, 10, 5, 1-cent
    int c[5] = {1, 5, 10, 25, 50};
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    while (cin >> n) {
        if (n <= 0) {
            cout << 1 << endl;
        }
        else {
            int N = n;
            vector<int> dp(n, 0);
            for (int i = 0; i < 5; i++) {
                for (int v = 0; v <= n; v++) {
                    for (int k = 0; k < n / c[i]; k++) {
                        if (v - k * c[i] >= 0) {
                            dp[v]

                        }
                    }
                }

            }
        }
    }
}