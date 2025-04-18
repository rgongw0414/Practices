class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Brute force Recursion: TC=(2^n), SC=O(n)
        return dfs(prices, 0, true);
    }

    int dfs(vector<int>& prices, int i, bool buying) {
        if (i >= prices.size()) return 0;
        int cooldown = dfs(prices, i + 1, buying); // The profit of neither buying nor selling today
        if (buying) {
            int buy = dfs(prices, i + 1, false) - prices[i]; // The profit of buying today
            return max(buy, cooldown);
        }
        else {
            int sell = dfs(prices, i + 2, true) + prices[i]; // The profit of selling today
            return max(sell, cooldown);
        }
    }
};

class Solution {
public:
    unordered_map<string, int> dp;
    int maxProfit(vector<int>& prices) {
        // DP Recursion: TC=(n), SC=O(n)
        return dfs(prices, 0, true);
    }

    int dfs(vector<int>& prices, int i, bool buying) {
        if (i >= prices.size()) return 0;
        string key = to_string(i) + "-" + to_string(buying);
        if (dp.count(key)) {
            return dp[key];
        }
        int cooldown = dfs(prices, i + 1, buying); // The profit of neither buying nor selling today
        if (buying) {
            int buy = dfs(prices, i + 1, false) - prices[i]; // The profit of buying today
            dp[key] = max(buy, cooldown);
        }
        else {
            int sell = dfs(prices, i + 2, true) + prices[i]; // The profit of selling today
            dp[key] = max(sell, cooldown);
        }
        return dp[key];
    }
};