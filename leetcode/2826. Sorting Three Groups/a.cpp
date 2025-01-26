class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        /*
        Consider nums = [2,1,3,2,1]
        Target: min dels, i.e., longest non-decreasing sub-sequence
        Method: 1-d dp, TC = O(n^2)
        */
        int max_len = 0;
        vector<int> LIS(nums.size(), 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < nums.size(); j++) {
                // LIS[i] = max(1, 1+LIS[i], 1+LIS[i+1], ..., 1+LIS[nums.size()-1])
                // LIS[i]: The longest len of seq which starts from i
                if (nums[i] <= nums[j]) {
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return (int)nums.size() - *max_element(LIS.begin(), LIS.end());
    }
};