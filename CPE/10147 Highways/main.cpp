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
        int n;
        cin >> n;
        int i = 0;
        vector<double> x(n, 0.0);
        vector<double> y(n, 0.0);
        int tmp = n;
        while (n--) {
            cin >> x[i] >> y[i++];
        }

        n = tmp;
        vector<vector<double>> mat(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                mat[i][j] = mat[j][i] = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
            }
        }

        int m;
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            mat[a-1][b-1] = mat[b-1][a-1] = 0.0;
        }

        vector<bool> visit(n, false);
        vector<double> dist(n, DBL_MAX);
        vector<int> parent(n, 0);
        dist[0] = 0.0;
		bool flag = true;
        for (int i = 0; i < n; i++) {
            int a = -1;
            double min = DBL_MAX;
            for (int j = 0; j < n; j++) {
                if (!visit[j] && dist[j] < min) {
                    a = j;
                    min = dist[j];
                }
            }
            if (a == -1) break;
            visit[a] = true;
			if (mat[a][parent[a]] != 0.0) {
                flag = false;
                cout << a+1 << " " << parent[a]+1 << endl;
            }
            for (int b = 0; b < n; b++) {
                if (!visit[b] && mat[a][b] < dist[b]) {
                    dist[b] = mat[a][b];
                    parent[b] = a;
                }
            }
        }

        if (flag) cout << "No new highways need\n";
        if (t > 0) cout << endl;
    }
}