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
    
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> hs;
        hs.reserve(p);
        while (p--) {
            int H;
            cin >> H;
            hs.eb(H);
        }
        int N = 0;
        vector<int> count(n+1, 0);
        for (int i = 1; i <= n; i++) {
            for (auto &h: hs) {
                if (i%h == 0) {
                    if (i%7 != 0 && i%7 != 6) {
                        if (!count[i]) count[i]++;
                    }
                }
            }
        }
        cout << accumulate(count.begin(), count.end(), 0) << endl;
    }
}