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
    int c = 1;
    while (t--) {
        cout << "Case #" << c++ << ": ";
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        while (m--) {
            int u, v, c;
            cin >> u >> v >> c;
            if (u == v) continue;
            if (c > mat[u][v]) mat[u][v] = mat[v][u] = c;
        }
        
        vector<bool> visit(n, false);
        vector<int> dist(n, INT_MIN);
        dist[0] = INT_MAX;
        vector<int> parent(n, -1);

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int a = -1;
            int max = INT_MIN;
            for (int j = 0; j < n; j++) {
                if (!visit[j] && dist[j] > max) {
                    a = j;
                    max = dist[j];
                }
            }
            if (a == -1) break;
            visit[a] = true;
            if (dist[a] < ans) ans = dist[a];

            for (int b = 0; b < n; b++) {
                if (!visit[b] && mat[a][b] > dist[b]) {
                    dist[b] = mat[a][b];
                    parent[b] = a;
                }
            }
        }
        cout << ans << endl;
    }
}