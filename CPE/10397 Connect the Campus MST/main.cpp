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
    
    int b;
    while (cin >> b) {
        vector<vector<double>> mat(b, vector<double>(b, 0.0));
        vector<pair<double, double>> coor;
        int tmp = b;
        while (b--) {
            double x, y;
            cin >> x >> y;
            coor.eb(make_pair(x, y));
        }
        b = tmp;
        for (int i = 0; i < b; i++) {
            for (int j = i+1; j < b; j++) {
                double len = sqrt(pow(coor[i].first - coor[j].first, 2) + pow(coor[i].second - coor[j].second, 2));
                mat[i][j] =  mat[j][i] = len;
            }
        }
        int e;
        cin >> e;
        while (e--) {
            int i, j;
            cin >> i >> j;
            mat[i-1][j-1] = mat[j-1][i-1] = 0.0; // force the selected edges to be included into MST
        }
        
        vector<double> dist(b, DBL_MAX);
        dist[0] = 0.0; // start prim's from node_0
        vector<bool> visit(b, false);
        vector<int> parent(b, 0);
        double ans = 0.0;
        for (int i = 0; i < b; i++) {
            int A = -1; // to note the node a in edge(a, b)
            double min = DBL_MAX;
            for (int j = 0; j < b; j++) {
                if (!visit[j] && dist[j] < min) {
                    A = j;
                    min = dist[j];
                }
            }
            if (A == -1) break;
            visit[A] = true;
            ans += dist[A];

            for (int B = 0; B < b; B++) {
                if (!visit[B] && mat[A][B] < dist[B]) {
                    dist[B] = mat[A][B];
                    parent[B] = A;
                }
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
}