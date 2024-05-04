class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer–Moore majority vote algorithm
        // Average/worset case TC: O(N), SC: O(1)
        // Algorithm prerequisite: There must be a majority in nums.
        // No solution:     nums = [1,1,2,2,3,4]
        // Solution exists: nums = [1,1,2,2,2,3]
        // *** Key idea on why this algo works: Because this majority element occurs more than n/2 (floor value) times, 
        //                                      even if other elements will 'vote against it', it will still win. ***
        int count = 0;
        int majority;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                // indicating that there are two different numbers with the same number of them before i (0 ~ i - 1)
                majority = nums[i];  // indicating that nums[i] might be the majority
            }
            if (nums[i] == majority) count++; // num vote for the majority
            else count--;  // other num vote against the majority
        }
        return majority;
    }
};