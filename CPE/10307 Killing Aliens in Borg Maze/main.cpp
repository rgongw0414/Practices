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
    while (t--) {
        int col, row;
        cin >> col >> row;
        vector<string> maze(row, string(col, ' '));
        cin.ignore(); // ignore the '\n' from previous cin

        int i = 0;
        vector<int> x; // coor of 'A' or 'S'
        vector<int> y;
        pair<int, int> coor_s; // coor of 'S' 
        while (row--) {
            string s;
            getline(cin, maze[i]);
            int j = 0;
            for (auto &c: maze[i]) { // transform the maze into an adj matrix
                if (c == 'A' || c == 'S') {
                    x.eb(i);
                    y.eb(j);
                    if (c == 'S') {
                        coor_s.first = i;
                        coor_s.second = j;
                    }
                }
                j++;
            }
            i++;
        }
        vector<vector<int>> mat(x.size(), vector<int>(x.size(), 0));
        for (int i = 0; i < x.size(); i++) {
            mat[x[i]][y[i]] = 1;
        }
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << ", " << y[i] << endl;
        }
        for (auto &r: mat) {
            for (auto &elem: r) {
                cout << elem << " ";
            }
            cout << endl;
        }
        // use BFS to abtain shortest path distance from S to As'
        
    }
}