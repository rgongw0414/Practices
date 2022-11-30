#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;

void solve() {
    
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    string n;
    while (cin >> n) {
        if (n == "0") break;
        cout << "Original number was " << stoll(n) << endl;
        ll length = 1;
        ll ascending, descending;
        sort(n.begin(), n.end());
        ascending = stoll(n);
        sort(n.begin(), n.end(), greater<char>());
        descending = stoll(n);
        ll nn = descending - ascending;
        set<ll> chain;
        chain.insert(nn);
        cout << descending << " - " << ascending << " = " << nn << endl;
        while (true) {
            length++;
            string s = to_string(nn);
            sort(s.begin(), s.end());
            ll asc = stoll(s);
            sort(s.begin(), s.end(), greater<char>());
            ll des = stoll(s);
            ll tmp = des - asc;
            cout << des << " - " << asc << " = " << tmp << endl;
            if (chain.count(tmp)) break;
            else chain.insert(tmp);
            s = to_string(tmp);
            nn = tmp;
        }
        cout << "Chain length " << length << endl << endl;
    }
}