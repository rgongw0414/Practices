class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Kadane's algorithm variation: Find the maximum circular subarray sum
        // Idea: The answer is either consists of a normal subarray or a circular subarray (start from the end and wrap around to the beginning)
        // 1. How to find the maximum normal subarray sum? Record the maximum sum of subarray, ref: 53. Maximum Subarray
        // 2. How to find the maximum circular subarray sum? It is equal to the total sum of the array minus the minimum normal subarray sum
        //    (because the minimum subarray sum is the part that is not included in the circular subarray)
        // Considering nums = [5,-3,5]
        // if [-3] is the minimum subarray sum, then the maximum subarray is the rest of [-3] is the maximum subarray
        // How to compute the sum of that? It is equal to: total - [-3]
        int curr_min = 0, curr_max = 0;
        int global_min = nums[0], global_max = nums[0];
        int total = 0;
        for (const int& num : nums) {
            curr_min = min(curr_min + num, num);
            curr_max = max(curr_max + num, num);
            total += num;
            global_min = min(global_min, curr_min);
            global_max = max(global_max, curr_max);
        }

        return (global_max > 0) ? max(global_max, total - global_min) : global_max;
        // For edge case of all negative numbers, where global_max is negative
        // if there is a positive number, global_max will be positive
    }
};