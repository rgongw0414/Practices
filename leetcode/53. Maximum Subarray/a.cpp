class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // DP, TC: O(N)
        int n = nums.size();
        vector<int> dp(n); // dp[i] stores the maximum subarray sum ending at index i
        dp[0] = nums[0]; // Base case: the maximum subarray sum ending at index 0 is nums[0]
        int ansMax = dp[0]; // Initialize ansMax with the maximum subarray sum so far
        
        for (int i = 1; i < n; ++i) {
            // The maximum subarray sum ending at index i can either include nums[i] or start a new subarray from nums[i]
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            // Update ansMax with the maximum subarray sum found so far
            ansMax = max(ansMax, dp[i]);
        }
        
        return ansMax;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm, TC: O(N)
        // Idea:
        // 1. Why discard the negative sum?
        // Because negative sum does not contribute to the answer,
        // more specifically, if we keep this negative sum, we will have to find "some numbers" to COMPENSATE the negative sum to positive,
        // which is contradicting to our goal of finding the maximum subarray sum, because we can just take these "numbers" as subarray which got positive sum.
        // 2. Why we not reset currSum to 0 when negative number is encountered?
        // Because the positive numbers' contribution to the sum is still greater than the currently included negative numbers' contribution,
        // where this statement stays true until the sum becomes negative.
        // Ref: https://neetcode.io/courses/advanced-algorithms/0
        int ansMax = nums[0];
        int currSum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            ansMax = max(ansMax, currSum);
            currSum = max(currSum, 0); // because negative sum does not contribute to the answer, 
            // so reset currSum to 0, which indicating starting a new subarray in next iteration
        }
        return ansMax;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm, TC: O(N)
        // Idea: Greedily include the current number, or start a new subarray from the current number
        // Ref: https://neetcode.io/courses/advanced-algorithms/0
        int ansMax = nums[0];
        int currSum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            ansMax = max(ansMax, currSum);
            currSum = max(currSum, nums[i]); // include the current number, or start a new subarray from the current number
        }
        return ansMax;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // brute-force: O(n^2)
        int ansMax = INT_MIN;
        for (size_t i = 0; i < nums.size(); i++) {
            int currMax = 0;
            for (size_t j = i; j < nums.size(); j++) {
                currMax += nums[j];
                ansMax = max(ansMax, currMax);
            }
        }
        return ansMax;
    }
};