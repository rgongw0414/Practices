class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(0, 0, 0, s1, s2, s3);
    }
    
    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3) {
        if (k == s3.length()) {
            return (i == s1.length()) && (j == s2.length());
        }
        
        if (i < s1.length() && s1[i] == s3[k]) {
            if (dfs(i + 1, j, k + 1, s1, s2, s3)) {
                return true;
            }
        }
        if (j < s2.length() && s2[j] == s3[k]) {
            if (dfs(i, j + 1, k + 1, s1, s2, s3)) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Top-down 2-d DP
        // TC: O(m*n), SC: O(m*n)
        if (s1.size() + s2.size() < s3.size()) return false;
        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1)); // +1 for end of string
        return dfs(s1, s2, s3, 0, 0, memo);
    }

    bool dfs(string& s1, string& s2, string& s3, int i1, int i2, vector<vector<int>>& memo) {
        if (i1 >= s1.size() && i2 >= s2.size()) return true;
        if (memo[i1][i2] != -1) return memo[i1][i2];
        if (i1 < s1.size() && s1[i1] == s3[i1 + i2] && dfs(s1, s2, s3, i1 + 1, i2, memo)) return true;
        if (i2 < s2.size() && s2[i2] == s3[i1 + i2] && dfs(s1, s2, s3, i1, i2 + 1, memo)) return true;
        memo[i1][i2] = false;
        return false;
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Bottom-up 2-d DP
        // TC: O(m*n), SC: O(m*n)
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) {
            return false;
        }

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for (int i = m; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i < m && s1[i] == s3[i + j] && dp[i + 1][j]) {
                    dp[i][j] = true;
                }
                if (j < n && s2[j] == s3[i + j] && dp[i][j + 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    }
};