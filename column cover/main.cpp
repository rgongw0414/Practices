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
    
    int x, y;
    cin >> x >> y;
    vector<vector<int>> mat(x, vector<int>(y, 0));
    vector<int> weights;
    while (y--) {
        int w;
        cin >> w;
        weights.eb(w);
    }
    while (cin >> x >> y) {
        mat[x-1][y-1] = 1;
    }

    
    // for (auto &r: mat) {
    //     for (auto &e: r) {
    //         cout << e << ' ';
    //     }
    //     cout << endl;
    // }
}