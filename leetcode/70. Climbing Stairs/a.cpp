class Solution {
public:
    int climbStairs(int n) {
        // Buttom-up: TC=SC=O(N)
        if (n <= 2) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // Space-Optimized: TC=O(N), SC=O(1)
        int one = 1, two = 1; // dp[1] = 1, dp[2] = 2
        
        for (int i = 0; i < n - 1; i++) {
            int temp = one; 
            one = one + two; // dp[i+2] = dp[i+1] + dp[i]
            two = temp;
        }
        
        return one;
    }
};

class Solution {
public:
    vector<int> cache;
    int climbStairs(int n) {
        // Top-down: TC=O(N), SC=O(N)
        // Calculate the number of ways to climb stairs from step-i to step-n.
        cache.resize(n, -1);
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        if (i >= n) return i == n;
        if (cache[i] != -1) return cache[i];
        return cache[i] = dfs(n, i + 1) + dfs(n, i + 2); // dp[i] = dp[i+1] + dp[i+2]
    }
};

class Solution {
public:
    int climbStairs(int n) {
        // Recursive: TC=O(2^N), SC=O(N)
        if (n <= 0) return 0;
        if (n <= 2) return n;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};