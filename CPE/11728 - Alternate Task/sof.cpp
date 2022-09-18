#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define endl '\n'
using namespace std;


// sum of prime factor

int c = 1;
vector<bool> P(1000, false);
vector<int> sof(1000, 0);

void solve(vector<int> &prime, int &s) {
    int ans = -1;
    if (s == 1) {
        cout << "Case " << c << ": " << 1 << endl;
        c++;
        return;
    }
    if (s == 2) {
        cout << "Case " << c << ": " << -1 << endl;
        c++;
        return;
    }
    
    if (P[s-1]) ans = s-1;
    else {
        for (int i = 3; i <= 1000; i++) {
            if (!P[i]) {
                if (sof[i] == s) {
                    ans = i;
                    break;
                }
            }
        }
    }
    cout << "Case " << c << ": " << ans << endl;
    c++;
}

void check(vector<int> &prime, int &i) {
    for (auto & p: prime) {
        if (i % p != 0) continue;
        else return;
    }
    prime.eb(i);
    P[i] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    vector<int> prime;
    prime.reserve(168);
    prime.eb(2);
    P[2] = true;
    for (int i = 3; i <= 1000; i++) {
        check(prime, i);
    }

    for (int i = 2; i <= 1000; i++) {
        if (!P[i]) {
            for (auto &p: prime) {
                if (i % p == 0) {
                    sof[i] += p;
                }
            }
        }
        else sof[i] = i + 1;
    }

    for (int i = 3; i <= 1000; i++) {
        if (!P[i]) {
            cout << i << ", " << sof[i] << endl;
        }
    }

    int s;
    while (cin >> s) {
        if (s == 0) break;
        // s <= 1000
        solve(prime, s);
    }
}