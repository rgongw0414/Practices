#include <bits/stdc++.h>
#define ll int
#define em emplace_back
#define endl '\n'
using namespace std;

void solve() {
    int magenta, yellow, cyan;
    cin >> magenta >> yellow >> cyan;
    string pixels;
    cin >> pixels;
    for (auto& p: pixels) {
        if (p == 'M') {
            magenta--;
        }
        else if (p == 'Y') {
            yellow--;
        }
        else if (p == 'C') {
            cyan--;
        }
        else if (p == 'R') {
            magenta--;
            yellow--;
        }
        else if (p == 'B') {
            magenta--;
            yellow--;
            cyan--;
        }
        else if (p == 'G') {
            cyan--;
            yellow--;
        }
        else if (p == 'V') {
            cyan--;
            magenta--;
        }
        else if (p == 'W') {
            continue;
        }
    }
    if (magenta < 0 || yellow < 0 || cyan < 0) cout << "NO" << endl;
    else cout << "YES " << magenta << " " << yellow << " " << cyan << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}