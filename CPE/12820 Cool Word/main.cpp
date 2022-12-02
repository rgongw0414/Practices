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
    int c = 1;
    while (cin >> n) {
        int cool = 0;
        while (n--) {
            map<char, int> dict;
            string s;
            cin >> s;
            for (auto &c: s) {
                if (dict.find(c) == dict.end()) dict[c] = 0;
                dict[c]++;
            }
            set<int> cnt;
            for (auto &e: dict) {
                cnt.insert(e.second);
            }
            if (dict.size() == cnt.size() && cnt.size() >= 2) cool++;
        }
        cout << "Case " << c++ << ": " << cool << endl;
    }
}