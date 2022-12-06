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
    
    int t;
    cin >> t;
    while (t--) {
        int f;
        cin >> f;
        vector<vector<double>> mat(f, vector<double>(f, 0.0));
        vector<pair<double, double>> coor(f, pair<double, double>(make_pair(0.0, 0.0)));
        auto iter = coor.begin();
        int tmp = f;
        while (f--) {
            double x, y;
            cin >> x >> y;
            (*iter).first += x;
            (*iter).second += y;
            iter++;
        }
        f = tmp;
        for (int i = 0; i < f; i++) {
            for (int j = i + 1; j < f; j++) { // build a complete graph
                double len = sqrt(pow(coor[i].first - coor[j].first, 2) + pow(coor[i].second - coor[j].second, 2));
                mat[i][j] = len;
                mat[j][i] = len;
            }
        }

        vector<bool> visit(f, false);
        vector<double> dist(f, DBL_MAX); // dist to tree
        vector<int> parent(f, 0); // parent of each node
        dist[0] = 0.0;
        for (int i = 0; i < f; i++) {
            int a = -1, b = -1;
            double min = DBL_MAX;
            for (int j = 0; j < f; j++) { // 選出不在樹(圖)上，離樹最近的點。
                if (!visit[j] && dist[j] < min) {
                    a = j; // 記錄當下最近的點
                    min = dist[j];
                }
            }
            if (a == -1) break;
            visit[a] = true;

            for (int b = 0; b < f; b++) { // 
                if (!visit[b] && mat[a][b] < dist[b]) {
                    dist[b] = mat[a][b];
                    parent[b] = a;
                }
            }
        }
        double ans = 0.0;
        for (int i = 1; i < f; i++) {
            ans += mat[i][parent[i]];
        }
        cout << fixed << setprecision(2) << ans << endl;
        if (t > 0) cout << endl;
    }
}