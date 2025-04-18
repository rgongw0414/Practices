class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 2-D Bottom-Up DP, TC: O(m*n), SC: O(m*n)
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[i][j]: The max size of the square starting from (i, j)
        int maxSquare = 0;

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (matrix[r][c] == '1') {
                    dp[r][c] = 1 + min({dp[r + 1][c], dp[r][c + 1], dp[r + 1][c + 1]});
                    maxSquare = max(maxSquare, dp[r][c]);
                }
            }
        }

        return maxSquare * maxSquare;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 1-D Bottom-Up DP, TC: O(m*n), SC: O(n)
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n + 1, 0);
        int maxSquare = 0;

        for (int r = m - 1; r >= 0; r--) {
            int prev = 0;
            for (int c = n - 1; c >= 0; c--) {
                int temp = dp[c];
                if (matrix[r][c] == '1') {
                    dp[c] = 1 + min({dp[c], dp[c + 1], prev});
                    maxSquare = max(maxSquare, dp[c]);
                } 
                else {
                    dp[c] = 0;
                }
                prev = temp;
            }
        }
        return maxSquare * maxSquare;
    }
};