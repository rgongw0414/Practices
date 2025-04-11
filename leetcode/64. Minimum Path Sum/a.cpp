class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Top-down DP
        // TC: O(m*n)
        // SC: O(m*n)
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(grid, 0, 0, memo);
    }

    int dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& memo) {
        if (row == grid.size() - 1 && col == grid[0].size() - 1) return grid[row][col];
        if (row  > grid.size() - 1 || col  > grid[0].size() - 1) return INT_MAX;
        if (memo[row][col] != -1) return memo[row][col];
        memo[row][col] = grid[row][col] + min(dfs(grid, row + 1, col, memo), dfs(grid, row, col + 1, memo));
        return memo[row][col];
    }
};