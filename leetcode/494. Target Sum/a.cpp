/* 
#######################################################################
  * Tricky for the bottom-up DP methods, because the table is sparse, 
and not intuitive to come up with.
########################################################################
*/

class Solution {
    vector<vector<int>> dp;
    int offset; // for negative index

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Top-down DP: TC=SC=O(N * sum(nums)), where N is the number of elements in nums and sum(nums) is the sum of all elements in nums.
        // where N is the number of elements in nums and totalSum is the sum of all elements in nums.
        // we need to offset the negative index by adding offset to it.
        offset = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * offset + 1, INT_MIN));
        return backtrack(0, 0, nums, target);
    }
    
    int backtrack(int i, int total, vector<int>& nums, int target) {
        if (i == nums.size()) {
            return total == target;
        }
        if (dp[i][total + offset] != INT_MIN) {
            return dp[i][total + offset];
        }
        dp[i][total + offset] = backtrack(i + 1, total + nums[i], nums, target) + 
                                  backtrack(i + 1, total - nums[i], nums, target);
        return dp[i][total + offset];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Top-down DP: TC=SC=O(N * sum(nums)), but may cost more than twice memory than pure vector, because of sparse hashmaps
        vector<unordered_map<int, int>> dp(nums.size() + 1);
        return backtrack(0, 0, nums, target, dp);
    }
    
    int backtrack(int i, int total, vector<int>& nums, int target, vector<unordered_map<int, int>>& dp) {
        if (i == nums.size()) {
            return (total == target);
        }
        if (dp[i].count(total)) {
            return dp[i][total];
        }
        dp[i][total] = backtrack(i + 1, total + nums[i], nums, target, dp) + 
                        backtrack(i + 1, total - nums[i], nums, target, dp);
        return dp[i][total];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Bottom-up 2-d DP: TC=O(N * totalSum), SC=O(N * totalSum)
        // where N is the number of elements in nums and totalSum is the sum of all elements in nums.
        int offset = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * offset + 1, 0)); // dp[i][cur_sum] = #ways to sum to cur_sum using nums[i], nums[i+1], ...
        dp[0][offset] = 1; // dp[0][0]: For cur_sum of 0, there's only 1 way that nums[0...] sum to 0.
        // idx:     0  ,      1  ,    offset, ...,  2*offset
        // sum: -offset, -offset + 1, ..., 0, ..., offset
        for (int i = 0; i < n; i++) {
            for (int s = 0; s <= 2*offset; s++) {
                if (dp[i][s] == 0) continue;
                if (s+nums[i] <= 2*offset) dp[i+1][s+nums[i]] += dp[i][s];
                if (s-nums[i] >= 0) dp[i+1][s-nums[i]] += dp[i][s];
            }
        }
        return (target+offset >= dp[0].size()) ? 0 : dp[n][target+offset];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Bottom-up 1-d DP: TC=O(N * offset), SC=O(offset)
        // where N is the number of elements in nums and totalSum is the sum of all elements in nums.
        int offset = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> dp(2 * offset + 1, 0); // dp[cur_sum] = #ways
        dp[offset] = 1; // dp[0]: For cur_sum of 0, there's only 1 way that nums[0...] sum to 0.
        // idx:     0  ,      1  ,    offset, ...,  2*offset
        // sum: -offset, -offset + 1, ..., 0, ..., offset
        for (int i = 0; i < n; i++) {
            vector<int> next_dp(2 * offset + 1, 0); // temp dp for next row
            for (int s = 0; s <= 2*offset; s++) {
                if (dp[s] == 0) continue;
                if (s+nums[i] <= 2*offset) next_dp[s+nums[i]] += dp[s];
                if (s-nums[i] >= 0)        next_dp[s-nums[i]] += dp[s];
            }
            dp = next_dp;
        }
        return (target+offset >= dp.size()) ? 0 : dp[target+offset];
    }
};