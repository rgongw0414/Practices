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
    
    string input;
    int b1, b2;
    while (cin >> input >> b1 >> b2) {
        int n = stoi(input, nullptr, b1);
        string ans = "";
        while (n/b2 > 0) {
            if (n%b2 >= 10 && b2 > 10) ans += ('A' + n%b2 - 10);
            else ans += to_string(n%b2);
            n /= b2;
        }
        if (n >= 10 && b2 > 10) ans += ('A' + n - 10);
        else ans += to_string(n);
        reverse(ans.begin(), ans.end());
        if (ans.size() > 7) ans = ans.substr(ans.size()-7, 7);
        cout << setw(7) << setfill('0') << ans << endl;
    }
}