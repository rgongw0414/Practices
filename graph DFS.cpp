class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // *** Note: If we don't care about BFS traversing nodes level by level, otherwise, 
        //           for graph, the difference b/w DFS is only the data structure used (i.e. stack for DFS or queue for BFS). ***
        // Backtracking (Iterative DFS), without revisiting visited places
        // Time: O(m*n)
        // Space: O(3*m*n) for pushing coordinates of 4 directions into stack
        int islandNum = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '0') continue;
                islandNum++;
                stack<pair<int, int>> stk; // stack of coordinates to visit
                stk.push({i, j});
                while (!stk.empty()) {
                    auto [iCurr, jCurr] = stk.top();
                    grid[iCurr][jCurr] = '0';
                    stk.pop();
                    for (auto &[di, dj]: directions)  {
                        // from (i, j), try to take one step horizontally or vertically
                        int iStepped = iCurr + di;
                        int jStepped = jCurr + dj;
                        if (iStepped >= 0 && iStepped < grid.size() && 
                                jStepped >= 0 && jStepped < grid[0].size() && grid[iStepped][jStepped] == '1') {
                            stk.push({iStepped, jStepped});
                        }
                    }
                }
            }
        }
        return islandNum;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Backtracking (DFS), without revisiting visited places
        // Time: O(m x n)
        // Space: O(m x n)
        int islandNum = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') islandNum++;
                traverse(grid, i, j);
            }
        }
        return islandNum;
    }

    void traverse(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        traverse(grid, i + 1, j);
        traverse(grid, i - 1, j);
        traverse(grid, i, j + 1);
        traverse(grid, i, j - 1);
        // grid[i][j] = '1'; we don't need this because we are traversing a island, once we stepped into a island, 
        // we would definitely traverse this island all the way, so we don't have to reset to '1' for revisiting.
        // Note that '1' is for revisiting, e.g. in word search II, each char can be reused by every strings.
    }
};