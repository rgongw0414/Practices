#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

void solve() {
    
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string p;
    while (cin >> p) {
        vector<char> str;
        // len:1~30
        int C = 0;
        int h = 0;
        for (auto& n: p) {
            char c;
            if (n == '0') c = '0';
            else if (n == '1') c = '1';
            else if (n == '-') {
                c = '-';
                h++;
            }
            else {
                C++;
                if (n == 'A' || n == 'B' || n == 'C') c = '2';
                else if (n == 'D' || n == 'E' || n == 'F') c = '3';
                else if (n == 'G' || n == 'H' || n == 'I') c = '4';
                else if (n == 'J' || n == 'K' || n == 'L') c = '5';
                else if (n == 'M' || n == 'N' || n == 'O') c = '6';
                else if (n == 'P' || n == 'Q' || n == 'R' || n == 'S') c = '7';
                else if (n == 'T' || n == 'U' || n == 'V') c = '8';
                else if (n == 'W' || n == 'X' || n == 'Y' || n == 'Z') c = '9';
            }
            str.eb(c);
        }
        for (auto &z: str) cout << z;
        cout << " " << C << " " << h << endl;
    }
}