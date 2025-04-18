class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Top-down DP, TC=SC=O(n * amount)
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, memo);
    }

    int dfs(int i, int a, vector<int>& coins, vector<vector<int>>& memo) {
        if (a == 0) return 1;
        if (i >= coins.size()) return 0;
        if (memo[i][a] != -1) return memo[i][a];

        int res = 0;
        if (a >= coins[i]) {
            res += dfs(i, a - coins[i], coins, memo);
        }
        res += dfs(i + 1, a, coins, memo);
        memo[i][a] = res;
        return res;
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Bottom-up 2-d DP, TC: O(n * amount), SC: O(n * amount)
        int n = coins.size();
        vector<vector<uint>> dp(n + 1, vector<uint>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                if (a >= coins[i]) {
                    dp[i][a] += dp[i][a - coins[i]];
                }
                dp[i][a] += dp[i + 1][a];
            }
        }
        return dp[0][amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Bottom-up 1-d DP, TC: O(n * amount), SC: O(amount)
        int n = coins.size();
        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                if (a - coins[i] >= 0) {
                    dp[a] += dp[a - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};