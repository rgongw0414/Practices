class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Bottom-up 2-D DP:  TC=SC=O(m∗n)
        if (text1.size() < text2.size()) swap(text1, text2);
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Bottom-up 1-D DP:  TC=O(m∗n), SC=O(1)
        if (text1.size() < text2.size()) swap(text1, text2);
        vector<int> dp(text2.size() + 1, 0);
        for (int i = text1.size() - 1; i >= 0; --i) {
            int prev = 0; // dp[i][j+1] is equivalent to dp[i+1][j+1]
            for (int j = text2.size() - 1; j >= 0; --j) {
                int temp = dp[j]; 
                if (text1[i] == text2[j]) 
                    dp[j] = 1 + prev;
                else 
                    dp[j] = max(dp[j], dp[j + 1]);
                prev = temp;
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Top-down DP:  TC=O(m∗n), SC=O(m∗n)
        if (text1.size() < text2.size()) swap(text1, text2);
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(text1, text2, memo, 0, 0);
    }

    int dfs(string &text1, string &text2, vector<vector<int>> &memo, int i1, int i2) {
        if (i1 == text1.size() || i2 == text2.size()) return 0;
        if (memo[i1][i2] != -1) return memo[i1][i2];
        if (text1[i1] == text2[i2])
            memo[i1][i2] = dfs(text1, text2, memo, i1 + 1, i2 + 1) + 1;
        else
            memo[i1][i2] = max(dfs(text1, text2, memo, i1 + 1, i2), 
                                dfs(text1, text2, memo, i1, i2 + 1));
        return memo[i1][i2];
    }
};