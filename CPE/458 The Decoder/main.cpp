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
    
    string s;
    while (cin >> s) {
        for (auto &c: s) {
            c = c - 7;
        }
        cout << s << endl;
    }
}