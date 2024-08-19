/*
    Given int array, determine min jumps to reach last index
    Ex. nums = [2,3,1,1,4] -> 2, index 0 to 1 to last

    Greedy: At each point, determine furthest reachable, jump to it

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        int curr_pos = 0;
        while (curr_pos < n - 1) {
            if (curr_pos + nums[curr_pos] >= n - 1) {
                result++;
                break;
            }
            int max_idx = curr_pos + 1;  // the next index to jump to, in order to arrive at max_reachable
            int max_reachable = 0;  // standing on curr_pos, the max reachable pos
            for (int j = curr_pos + 1; j <= curr_pos + nums[curr_pos]; j++) {
                // j: standing on curr_pos, the reachable fields
                if (j + nums[j] > max_reachable) {
                    // from curr_pos, if jump to j, and the reachable pos from j > max_reachable, then GREEDILY take j as the next pos to jump to.
                    max_idx = j;
                    max_reachable = j + nums[j];
                }
            }
            curr_pos = max_idx;
            result++;
        }
        
        return result;
    }
};
