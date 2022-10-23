#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

void solve(string t) {
    if (t.size() == 1) {
        cout << t << endl;
        return;
    }
    ll sum = 0;
    for (auto& n: t) {
        sum += n - '0';
    }
    solve(to_string(sum));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string t;
    while (cin >> t) {
        if (t == "0") break;
        solve(t);
    }
}