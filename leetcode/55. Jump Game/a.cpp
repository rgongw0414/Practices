class Solution {
public:
    bool canJump(vector<int>& nums) {
        // greedy with TC of O(N), in a way similar to Kadane's algorithm
        // dynamically updates reachable position, pushing it from head to tail
        int currReachable = 0;
        for (int curr_pos = 0; curr_pos < nums.size(); curr_pos++) {
            if (currReachable < curr_pos || currReachable >= nums.size() - 1) {
                // curr_pos can't be reached, meaning that we can't not go any further
                break;
            }
            currReachable = max(currReachable, curr_pos + nums[curr_pos]);
        }
        return (currReachable >= nums.size() - 1);
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1; // target position
        bool ans; // can jump to target
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= target) {
                // it is possible to jump from i to target
                target = i;
                ans = true;
            }
            else {
                ans = false;
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // brute-force: O(N^N) for TC
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