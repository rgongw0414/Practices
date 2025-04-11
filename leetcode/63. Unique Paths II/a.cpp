class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Bottom-up 1-d DP
        // TC: O(m*n)
        // SC: O(n)
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 0);
        dp[0] = 1; // column 0 set to 1, because we can only go down from the top-left corner
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else {
                    if (j == 0) continue; // fix column 0 to 1, unless there is an obstacle
                    if (j > 0) dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        return dp[n-1];
    }
};