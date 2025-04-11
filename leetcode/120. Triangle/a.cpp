/*
2 
4 3

j
7 6 5      i
11 8 9 10  i+1
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Method: Bottom-up 1-d DP
        // TC: O(n^2)
        // SC: O(n)
        // n = #row
        int r_n = triangle.size(); // #row
        vector<int> dp(triangle.back());
        for (int i = r_n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Bottom-up 2-d DP
        // TC: O(n^2), n = #row
        // SC: O(n^2)
        int n = triangle.size(); // #row
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp.back().assign(triangle.back().begin(), triangle.back().end());
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Top-down 2-d DP 
        // TC: O(n^2), n = #row
        // SC: O(n^2)
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return dfs(triangle, 0, 0, dp);
    }

    int dfs(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        if (i >= triangle.size() || j >= triangle[i].size()) return 0;
        if (dp[i][j] != INT_MAX) return dp[i][j]; // resolved before
        dp[i][j] = triangle[i][j] + min(dfs(triangle, i+1, j, dp), dfs(triangle, i+1, j+1, dp));
        return dp[i][j];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Top-down Recursion DP
        // TC: O(2^n), n = #row
        // SC: O(n)
        return dfs(triangle, 0, 0);
    }

    int dfs(vector<vector<int>>& triangle, int i, int j) {
        if (i >= triangle.size() || j >= triangle[i].size()) return 0;

        return triangle[i][j] + min(dfs(triangle, i+1, j), dfs(triangle, i+1, j+1));
    }
};