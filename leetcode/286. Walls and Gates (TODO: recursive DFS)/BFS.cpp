class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
public:
/* L: land
 [
  [L,-1, 0, L],
  [L, L, L,-1],
  [L,-1, L,-1],
  [0,-1, L, L]
]
*/
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Time:  O(m x n)
        // Space: O(m x n)
        // BFS: It is a little tricky that it first pushes all land cells into the queue.
        // If a land cell cannot reach a treasure chest than the value should remain INF_MAX.
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j}); // TRICKS!!!
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (auto& coor: directions) {
                int iStepped = i + coor.first; // coordinate after stepped
                int jStepped = j + coor.second;
                if (iStepped < 0 || iStepped >= grid.size() || 
                        jStepped < 0 || jStepped >= grid[0].size() || grid[iStepped][jStepped] != INT_MAX) {
                    // out-of-bound, not a land, or has been stepped in before.
                    continue;
                }
                grid[iStepped][jStepped] = grid[i][j] + 1;
                q.push({iStepped, jStepped});
            }
        }
    }
};
