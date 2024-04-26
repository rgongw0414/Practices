class Solution {
public:
    bool canJump(vector<int>& nums) {
        // brute-force: O(N^2) for TC
        vector<bool> reachable(nums.size(), false);
        reachable[0] = true;

        for (size_t i = 0; i < nums.size(); i++) {
            if (!reachable[i] || reachable[nums.size() - 1]) break;
            for (size_t j = 1; j <= nums[i]; j++) {
                if (i + j >= nums.size()) break;
                reachable[i + j] = true;
            }
        }
        return reachable[nums.size() - 1];
    }
};