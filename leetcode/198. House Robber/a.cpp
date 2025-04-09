class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int dp1 = nums[0]; // max money by robbing house-0 to (including) house-i
        int dp2 = max(nums[0], nums[1]);
        for (int i = 2 ; i < n; i++) {
            //       dp1 dp2 cur
            // nums = [2, 7, 9, 3, 1]
            int curr = max(dp1 + nums[i], dp2); // take nums[i] or not
            dp1 = dp2;
            dp2 = curr;
        }
        return dp2;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        // Bottom-up DP
        // TC=O(n), SC=O(n)
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, 0); // dp[i]: max money by robbing house-0 to (including) house-i
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2 ; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};