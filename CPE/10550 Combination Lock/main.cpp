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
    
    int s, a, b, c;
    while (cin >> s >> a >> b >> c) {
        if (!s && !a && !b && !c) break;
        int sum = 0;
        sum += 40*2;
        sum = sum + (40+s-a)%40;
        sum += 40;
        sum = sum + (40+b-a)%40;
        sum = sum + (40+b-c)%40;

        cout << sum * 9 << endl;
    }
}