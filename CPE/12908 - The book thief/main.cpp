#include <bits/stdc++.h>
#define ll int
#define em emplace_back
#define endl '\n'
using namespace std;

void solve(ll &s){
    int tmp = 0;
    for (ll i = 1; i < INT_MAX; i++) {
        tmp = i*(i+1)/2;
        for (ll j = i; j > 0; j--) {
            if (tmp - j == s) {
                cout << j << " " << i << endl;
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll s; // result sum, 1 <= s <= 1e8
    while (cin >> s){
        if (s <= 0) break;
        else {
            solve(s);
        }
    }
}