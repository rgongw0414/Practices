#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

vector<bool> solve(char n) {
    vector<bool> f(11, false); // 1 ~ 10
    if (n == 'c') {
        f[2] = true;
        f[3] = true;
        f[4] = true;
        f[7] = true;
        f[8] = true;
        f[9] = true;
        f[10] = true;
    }
    else if (n == 'd') {
        f[2] = true;
        f[3] = true;
        f[4] = true;
        f[7] = true;
        f[8] = true;
        f[9] = true;
    }
    else if (n == 'e') {
        f[2] = true;
        f[3] = true;
        f[4] = true;
        f[7] = true;
        f[8] = true;
    }
    else if (n == 'f') {
        f[2] = true;
        f[3] = true;
        f[4] = true;
        f[7] = true;
    }
    else if (n == 'g') {
        f[2] = true;
        f[3] = true;
        f[4] = true;
    }
    else if (n == 'a') {
        f[2] = true;
        f[3] = true;
    }
    else if (n == 'b') {
        f[2] = true;
    }
    else if (n == 'C'){
        f[3] = true;
    }
    else if (n == 'D') {
        f[1] = true;
        f[2] = true;
        f[3] = true;
        f[4] = true;
        f[7] = true;
        f[8] = true;
        f[9] = true;
    }
    else if (n == 'E') {
        f[1] = true;
        f[2] = true;
        f[3] = true;
        f[4] = true;
        f[7] = true;
        f[8] = true;
    }
    else if (n == 'F') {
        f[1] = true;
        f[2] = true;
        f[3] = true;
        f[4] = true;
        f[7] = true;
    }
    else if (n == 'G') {
        f[1] = true;
        f[2] = true;
        f[3] = true;
        f[4] = true;
    }
    else if (n == 'A') {
        f[1] = true;
        f[2] = true;
        f[3] = true;
    }
    else if (n == 'B') {
        f[1] = true;
        f[2] = true;
    }
    return f;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> fc(11, 0); // use fc[1] ~ fc[10]
        auto n = s.begin();
        while (true) {
            auto now = solve(*n);
            n++;
            if (n == s.end()) break;
            else auto next = solve(*n);
            for (int i = 1; i <= 10; i++) {
                if (!now[i] && next[i]) fc[i]++;
            }
            n++;
        }
        for (int i = 1; i <= 10; i++) {
            cout << fc[i] << " ";
        }
        cout << endl;
    }
}