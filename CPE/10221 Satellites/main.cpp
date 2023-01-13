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
    
    int ss, aa;
    string A;
    double pi = acos(-1);
    while (cin >> ss >> aa >> A) {
        if (A == "deg") {
            int aaa = aa%180;
            double s = ss;
            double a = aaa;
            if (a > 180) a = 360 - a;
            else if (a == 0 && (aa/180)%2 == 1) a = 180;
            cout << fixed << setprecision(6) << abs(2.0*(6440.0+s)*pi*(a/360.0)) << " ";
            cout << fixed << setprecision(6) << abs(2.0*(sin(a/2.0/180.0*pi)*(6440.0+s))) << endl;
        }
        else if (A == "min") {
            // TODO: 180, 181~360
            double s = ss;
            double a = aa;
            cout << fixed << setprecision(6) << abs(2.0*(6440.0+s)*pi*(a/60.0/360.0)) << " ";
            cout << fixed << setprecision(6) << abs(2.0*(sin(a/2.0/60.0/180.0*pi)*(6440.0+s))) << endl;
        }
    }
}