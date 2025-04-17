class Solution {
public:
    int minDistance(string word1, string word2) {
        // Bottom-up DP, TC: O(m*n), SC: O(m*n)
        // dp[i][j] = min distance of word1[i...] and word2[j...]
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) dp[i][n] = m - i; // #insertion needed for empty word2 and word1[i...]
        for (int i = 0; i < n; i++) dp[m][i] = n - i; // #deletion needed for empty word1 and word2[j...]
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }
                else {
                    // +1 for substituting word1[i] to word2[j]
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};