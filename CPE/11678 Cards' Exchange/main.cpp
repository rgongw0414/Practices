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
    
    int a, b;
    while (cin >> a >> b) {
        if (!a && !b) break;
        set<int> A, B;
        while (a--) {
            int n;
            cin >> n;
            A.insert(n);
        }
        while (b--) {
            int n;
            cin >> n;
            B.insert(n);
        }

        int cntA = 0;
        for (auto &elem: A) {
            if (!B.count(elem)) cntA++;
        }
        int cntB = 0;
        for (auto &elem: B) {
            if (!A.count(elem)) cntB++;
        }
        cout << min(cntA, cntB) << endl;
    }
}