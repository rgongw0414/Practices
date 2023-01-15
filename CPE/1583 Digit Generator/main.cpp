#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<int> list(100000+1, INT_MAX);
    for (int i = 1; i <= 100000; i++) {
        int sum = 0;
        string str = to_string(i);
        sum += i;
        for (auto &d: str) sum += d - '0';
        if (sum > 100000) continue;
        if (i < list[sum]) list[sum] = i;
    }
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (list[n] == INT_MAX) cout << 0 << endl;
        else cout << list[n] << endl;
    }
}