class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r-l) / 2;
            if (nums[m] == target) {
                ans = m;
                break;
            }
            if (nums[l] <= nums[m]) {
                // *** discuss the sorted halves first ***
                // the left half is sorted, and target is in the left half, so search the left half
                if (nums[l] <= target and target < nums[m])
                    r = m - 1;
                else 
                    l = m + 1;
            }
            else if (nums[m] <= nums[r]) {
                // *** equivalent to else {...} ***
                // since in a sorted rotated array, either the left half, or the right half is sorted.
                if (nums[m] < target and target <= nums[r])
                    l = m + 1;
                else 
                    r = m - 1;
            }
        }
        return ans;
    }
};