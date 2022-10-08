#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

char solve() {
    string n;
    // n.reserve(1000);
    cin >> n;
    char win;
    int sum = 0;
    multiset<int> digs;
    for (auto &c: n) {
        digs.insert(c);
        sum += c-'0';
    }
    bool sFound = false, tFound = false;
    while (true) {
        int N;
        for (auto &c: digs) {
            if (!sFound && (sum - c) % 3 == 0) {
                sum  = sum - c;
                N = c;
                sFound = true;
            }
        }
        if (!sFound) {
            win = 'T';
            break;
        }
        else digs.erase(digs.find(N));

        for (auto &c: digs) {
            if (!tFound && (sum - c) % 3 == 0) {
                sum  = sum - c;
                N = c;
                tFound = true;
            }
        }
        if (!tFound) {
            win = 'S';
            break;
        }
        else digs.erase(digs.find(N));

        if (sFound) sFound = false;
        if (tFound) tFound = false;
    }
    return win;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t, c = 1;
    char win;
    cin >> t;
    while (t--) {
        win = solve();
        cout << "Case " << c << ": " << win << endl;
        c++;
    }
}