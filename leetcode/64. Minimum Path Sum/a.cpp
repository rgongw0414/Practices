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

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Bottom-up 2-d DP
        // TC: O(m*n)
        // SC: O(m*n)
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<vector<int>> dp(ROWS + 1, vector<int>(COLS + 1, INT_MAX));
        dp[ROWS][COLS - 1] = 0; // for the sake of the target (the bottom right square)
        for (int r = ROWS - 1; r >= 0; r--) {
            for (int c = COLS - 1; c >= 0; c--) {
                dp[r][c] = grid[r][c] + min(dp[r + 1][c], dp[r][c + 1]);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Bottom-up 2-d DP
        // TC: O(m*n)
        // SC: O(n)
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> dp(COLS + 1, INT_MAX);
        dp[COLS - 1] = 0; // for the rightmost square in each row (s.t. min(dp[c], dp[c + 1]) == 0)
        for (int r = ROWS - 1; r >= 0; r--) {
            for (int c = COLS - 1; c >= 0; c--) {
                dp[c] = grid[r][c] + min(dp[c], dp[c + 1]);
            }
        }
        return dp[0];
    }
};