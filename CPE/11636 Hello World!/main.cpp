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
    
    vector<int> list(10000+1, 0);
    int i = 2, n = 0;
    while (i <= 10000) {
        int tmp = pow(2, n);
        while (tmp--) {
            list[i++] = n+1;
            if (i > 10000) break;
        }
        n++;
    }

    int t, c = 1;
    while (cin >> t) {
        if (t < 0) break;
        cout << "Case " << c++ << ": " << list[t] << endl;
    }
}