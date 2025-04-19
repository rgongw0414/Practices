class Solution {
public:
    int numDistinct(string s, string t) {
        // Brute Recursion: TC=O(2^m), SC=O(m)
        int m = s.size(), n = t.size();
        if (m < n) return 0;
        return dfs(s, t, 0, 0);
    }

    int dfs(string& s, string& t, int i1, int i2) {
        if (i2 >= t.size()) return 1;
        if (i1 >= s.size()) return 0;
        int res = dfs(s, t, i1+1, i2); // not taking s[i]
        if (s[i1] == t[i2]) res += dfs(s, t, i1+1, i2+1); // taking s[i]
        return res;
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        // Top-down DP: TC=SC=O(m)
        int m = s.size(), n = t.size();
        if (m < n) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return dfs(s, t, 0, 0, dp);
    }

    int dfs(string& s, string& t, int i1, int i2, vector<vector<int>>& dp) {
        if (i2 >= t.size()) return 1;
        if (i1 >= s.size()) return 0;
        if (dp[i1][i2] != -1) return dp[i1][i2];

        dp[i1][i2] = dfs(s, t, i1+1, i2, dp); // not taking s[i]
        if (s[i1] == t[i2]) dp[i1][i2] += dfs(s, t, i1+1, i2+1, dp); // taking s[i]
        return dp[i1][i2];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        // Bottom-up 2-d DP: TC=SC=O(m*n)
        int m = s.length(), n = t.length();
        if (n > m) return 0;

        vector<vector<uint>> dp(m + 1, vector<uint>(n + 1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j]; // not taking s[i]
                if (s[i] == t[j]) {
                    dp[i][j] += dp[i + 1][j + 1]; // taking s[i]
                }
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        // Bottom-up 1-d DP: TC=O(m*n), SC=O(n)
        int m = s.length(), n = t.length();
        if (n > m) return 0;

        vector<uint> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            vector<uint> next_dp(n + 1, 0);
            next_dp[n] = 1;
            for (int j = n - 1; j >= 0; j--) {
                next_dp[j] = dp[j]; // not taking s[i]
                if (s[i] == t[j]) {
                    next_dp[j] += dp[j + 1]; // taking s[i]
                }
            }
            dp = next_dp;
        }
        return dp[0];
    }
};