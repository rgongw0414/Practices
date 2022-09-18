#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;

int c = 1;
vector<int> sof(1001, -1);

void solve(vector<int> &sof, int &s) {
    for (int i = 1000; i > 0; i--) {
        if (sof[i] == s) {
            cout << "Case " << c << ": " << i << endl;
            c++;
            return;
        }
    }
    cout << "Case " << c << ": " << -1 << endl;
    c++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    for (int i = 1; i <= 1000; i++) {
        int tmp = 0;
        for (int j = 1; j <= (i); j++) {
            if (i % j == 0) {
                tmp += j;
            }
        }
        // if (i != 1) tmp += i;
        sof[i] = tmp;
        // cout << i << ", " << sof[i] << endl;
    }

    int s;
    while (cin >> s) {
        if (s == 0) break;
        // s <= 1000
        
        solve(sof, s);
    }
}