#include <bits/stdc++.h>
#define ll long long
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

void solve() {
    string input;
    string table("zxcvbnm,./asdfghjkl;\'qwertyuiop[]`1234567890-=\\");
    getline(cin,  input);
    vector<char> output;
    output.reserve(input.size());
    for (auto &c: input) {
        char d, lc = tolower(c);
        if (c == '\n') d = '\n';
        else if (c == '\t') d = '\t';
        else if (lc == 'z') d = 'z';
        else if (lc == 'x') d = 'x';
        else if (lc == ' ') d = ' ';
        else {
            for (int i = 2; i < table.size(); i++) {
                if (lc == table[i]) d = table[i-2];
            }
        }
        output.eb(d);
    }
    for (auto &c: output) {
        cout << c;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        solve();
    }
}