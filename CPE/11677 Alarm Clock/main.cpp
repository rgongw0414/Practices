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
    
    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2) {
        if (!h1 & !m1 & !h2 & !m2) break;
        if (h1 == 0) h1 = 24;
        if (h2 == 0) h2 = 24;
        int m = 0;
        m += (60 - m1);
        h1++;
        m1 = 0;
        m += (h2-h1)*60 + m2;
        if (m < 0) m += 60*24;
        cout << m << endl;
    }
}