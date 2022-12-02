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
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int g = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                g += __gcd(i, j);
            }
        }
        cout << g << endl;
    }
}