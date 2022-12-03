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
    int Case = 1;
    while (t--) {
        string input;
        cin >> input;
        int n = 0;
        char prev;
        vector<char> ans;
        int cnt = 1;
        for (auto &c: input) {
            if (c >= 'A' && c <= 'Z') {
                if (n != 0) {
                    for (int i = 0; i < n; i++) ans.eb(prev);
                    n = 0;
                }
                prev = c;
            }
            else {
                n *= 10;
                n += c - '0';
            }
            if (cnt == input.size()) {
                for (int i = 0; i < n; i++) ans.eb(prev);
            }
            cnt++;
        }
        cout << "Case " << Case++ << ": ";
        for (auto &c: ans) cout << c;
        cout << endl;
    }
}