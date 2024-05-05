class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Iterative BFS
        // Time: O(m*n)
        // Space: O(3*m*n) for pushing coordinates of 4 directions into stack
        int islandNum = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < (int)grid.size(); i++) {
            for (int j = 0; j < (int)grid[0].size(); j++) {
                if (grid[i][j] == '0') continue;
                islandNum++;
                grid[i][j] = '0';  // ***** differs from DFS!!! *****
                queue<pair<int, int>> q; // stack of coordinates to visit
                q.push({i, j});
                while (!q.empty()) {
                    auto [iCurr, jCurr] = q.front();
                    // grid[iCurr][jCurr] = '0'; // ***** differs from DFS!!! *****
                    q.pop();
                    for (auto &[di, dj]: directions)  {
                        // from (i, j), try to take one step horizontally or vertically
                        int iStepped = iCurr + di;
                        int jStepped = jCurr + dj;
                        if (iStepped >= 0 && iStepped < (int)grid.size() && 
                                jStepped >= 0 && jStepped < (int)grid[0].size() && grid[iStepped][jStepped] == '1') {
                            q.push({iStepped, jStepped});
                            grid[iStepped][jStepped] = '0'; // ***** differs from DFS!!! *****
                            // if coding in DFS manner, the front coordinate will be revisited, and causing TLE!!!
                        }
                    }
                }
            }
        }
        return islandNum;
    }
};