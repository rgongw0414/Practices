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
    
    int t;
    cin >> t;
    cin.ignore();
    map<string, int> list;
    while (t--) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string country;
        ss >> country;
        if (list.count(country)) list[country]++;
        else list[country] = 1;
    }
    for (auto &elem: list) {
        cout << elem.first << " " << elem.second << endl;
    }
}