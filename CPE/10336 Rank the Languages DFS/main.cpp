#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl '\n'
#define eb emplace_back
#define ef emplace_front
using namespace std;


int m, n;

void dfs(vector<vector<char>> &maze, vector<vector<bool>> &visited, int i, int j) {
    visited[i][j] = true;
    // (0, 0) ~ (m-1, n-1)
    if (j+1 < n && maze[i][j+1] == maze[i][j] && !visited[i][j+1]) // right
        dfs(maze, visited, i, j+1);
    if (j-1 >= 0 && maze[i][j-1] == maze[i][j] && !visited[i][j-1]) // left
        dfs(maze, visited, i, j-1);
    if (i-1 >= 0 && maze[i-1][j] == maze[i][j] && !visited[i-1][j]) // up
        dfs(maze, visited, i-1, j);
    if (i+1 < m && maze[i+1][j] == maze[i][j] && !visited[i+1][j]) // down
        dfs(maze, visited, i+1, j);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    int c = 1;
    while (t--) {
        cout << "World #" << c++ << endl;
        cin >> m >> n;
        vector<vector<char>> maze(m, vector<char>(n, ' '));
        vector<int> count(26, 0);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)  {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                maze[i][j] = s[j];
            }
        }

        int max = INT_MIN;
        for (int i = 0; i < m; i++)  {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    count[maze[i][j]-'a']++;
                    if (max < count[maze[i][j]-'a']) {
                        max = count[maze[i][j]-'a'];
                    }
                    dfs(maze, visited, i, j);
                }
            }
        }

        for (int i = max; i >= 1; i--) {
            for (int j = 0; j < 26; j++) {
                if (i == count[j]) {
                    char ans = 'a' + j;
                    cout << ans << ": " << count[j] << endl;
                }
            }
        }
        // for (int i = 0; i < m; i++)  {
        //     for (int j = 0; j < n; j++) {
        //         cout << visited[i][j];
        //     }
        //     cout << endl;
        // }
    }
}