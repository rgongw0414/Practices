/*
Since House[1] and House[n] are adjacent, they cannot be robbed together. 
Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. 
Now the problem has degenerated to the House Robber, which is already been solved. */
class Solution {
public:
    int rob(vector<int>& nums) {
        // House Robber II
        // TC=O(n), SC=O(1)
        int n = nums.size();
        if (n == 1) return nums[0]; // Edge case: only one house
        // Option 1: Rob houses 0 to n-2
        // Option 2: Rob houses 1 to n-1
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }

    int solve(vector<int>& nums, int start, int end) {
        if (start > end) return 0; // Invalid range

        int dp1 = 0; // Represents the max profit one house before
        int dp2 = 0; // Represents the max profit two houses before

        for (int i = start; i <= end; i++) {
            int curr = max(nums[i] + dp2, dp1); // Rob current house or skip it
            dp2 = dp1; // Update two houses back
            dp1 = curr; // Update one house back
        }

        return dp1; // Max profit for range start to end
    }
};