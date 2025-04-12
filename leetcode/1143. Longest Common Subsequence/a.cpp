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