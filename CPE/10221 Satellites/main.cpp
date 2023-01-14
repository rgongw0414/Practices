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
    
    double s, a;
    string A;
    double pi = acos(-1);
    while (cin >> s >> a >> A) {
        if (A == "min") a /= 60;
        a = fmod(a, 360.0);
        if (a > 180.0) a = 360.0 - a;
        cout << fixed << setprecision(6) << 2.0*(6440.0+s)*pi*(a/360.0) << " ";
        cout << fixed << setprecision(6) << abs(2.0*(sin((a/2.0/180.0)*pi) * (6440.0+s))) << endl;
    }
}