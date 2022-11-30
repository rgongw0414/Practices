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
    
    string maker;
    int T, t, l, h;
    cin >> T;
    bool start = false;
    while (T--) {
        if (start) cout << endl;
        else start = !start;
        cin >> t;
        map<string, pair<int, int>> m;
        while (t--) {
            cin >> maker >> l >> h;
            m[maker] = make_pair(l, h);
        }
        cin >> t;
        while (t--) {
            int p;
            cin >> p;
            string ans = "UNDETERMINED";
            for (auto &car: m) {
                if (car.second.first <= p && p <= car.second.second) {
                    if (ans == "UNDETERMINED") ans = car.first;
                    else {
                        ans = "UNDETERMINED";
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
    }
}