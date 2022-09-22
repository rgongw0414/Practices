#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define endl '\n'
using namespace std;

int Case = 1;
void solve(int sx, int sy, int dx, int dy) {
    // 0 <= coor. <= 1e5
    // N(x, y): N = (1 + 2 + ... + (x+y+1-1)) + x = (x+y)*(x+y+1)/2 + x
    int sn = (sx+sy)*(sx+sy+1)/2 + sx;
    int dn = (dx+dy)*(dx+dy+1)/2 + dx;
    cout << "Case " << Case++ << ": " << dn-sn << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n <= 0) return 0;
    while (n--) {
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        solve(sx, sy, dx, dy);
    }
}