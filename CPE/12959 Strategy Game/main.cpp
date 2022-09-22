#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int j, r, n;
    while (cin >> j >> r) {
        if (j == 0 && r == 0) break;
        vector<int> vp(j, 0);
        // n = j * r;
        while (r--) {
            for (auto& p: vp) {
                cin >> n;
                p += n;
            }
        }
        int max = 0;
        for (int i = 1; i < j; i++) {
            if (vp[i] >= vp[max]) max = i;
        }
        cout << max + 1 << endl;
    }
}