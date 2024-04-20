class Solution {
public:
    int findMin(vector<int>& nums) {
        // special binary search
        // *** in a sorted rotated array, either the left half, or the right half is sorted. ***
        // *** discuss the sorted halves first ***
        int l = 0, r = nums.size() - 1;
        int ans = INT_MAX;
        while (l <= r) {
            int m = l + (r-l) / 2;
            ans = min(ans, nums[m]);
            if (nums[l] < nums[r]) {
                // early stopping, if the current region is sorted
                ans = min(ans, nums[l]);
                break;
            }
            if (nums[m] < nums[r]) { 
                // if the right half is sorted, then search the left half
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};