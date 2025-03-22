class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // TC:O(n), SC:O(1)
        int summation = 0;
        int l = 0, r = 0;
        int n = nums.size();
        int min_len = INT_MAX;
        while (r < n) {
            summation += nums[r];
            while (summation >= target) {
                min_len = min(min_len, r - l + 1);
                summation -= nums[l];
                l++;
            }
            r++;
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};