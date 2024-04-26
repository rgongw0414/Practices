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
        // greedy with TC of O(N), note that using size_t as index type in for loop will cause overflowing.
        // dynamically updates goal position, pushing it from tail to head
        int goal = nums.size() - 1;
        for (int curr_pos = nums.size() - 1; curr_pos >= 0; curr_pos--) {
            // size_t will cause curr_pos overflow to UINT_MAX in the last iteration of for loop (last iter: 0 - 1 = UINT_MAX)
            if (curr_pos + nums[curr_pos] >= goal) goal = curr_pos;
        }
        bool reachable = (goal == 0);
        return reachable;
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