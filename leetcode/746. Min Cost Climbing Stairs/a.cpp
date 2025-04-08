class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Bottom-Up DP Space Optimized
        // TC: O(n)
        // SC: O(1)
        // Idea: We can reduce the space complexity from O(n) to O(1) by using two variables to keep track of the last two costs.
        /*
                f  s  c   ...
        cost = [1,100,1,1,1,100,1,1,100,1]
                   f  s c ... 
        */
        int first = 0, second = 0;
        for (int i = 2; i <= cost.size(); i++) {
            int current = min(first + cost[i - 2], second + cost[i - 1]); // takes 'current' to get to the i-th step
            first = second;
            second = current;
        }
        return second;
        // for (int i = cost.size() - 3; i >= 0; i--) {
        //     cost[i] += min(cost[i + 1], cost[i + 2]);
        // }
        // return min(cost[0], cost[1]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Bottom-Up DP
        // TC: O(n)
        // SC: O(n)
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Recursive Top-Down DP
        // TC: O(2^n)
        // SC: O(n)
        return dfs(cost, cost.size());
    }
    int dfs(vector<int>& cost, int i) {
        if (i <= 1) return 0;
        return min(dfs(cost, i - 1) + cost[i-1], dfs(cost, i - 2) + cost[i-2]);
    }
};