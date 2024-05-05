class Solution {
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
        // More readable than BFS.cpp
        // recursive DFS start traversing from chests (gates)
        // TC: O(m x n), SC: O(m x n)
        // If a land cell cannot reach a treasure chest than the value should remain INF_MAX.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    DFS(grid, i, j, 0);
                }
            }
        }
    }

    void DFS(vector<vector<int>>& grid, int i, int j, int distanceFromChest) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || distanceFromChest > grid[i][j]) {
            // out-of-bound, or the distance from the chest is greater than the current distance.
            return;
        }
        grid[i][j] = distanceFromChest;
        distanceFromChest++;
        DFS(grid, i + 1, j, distanceFromChest);
        DFS(grid, i - 1, j, distanceFromChest);
        DFS(grid, i, j + 1, distanceFromChest);
        DFS(grid, i, j - 1, distanceFromChest);
    }
};
