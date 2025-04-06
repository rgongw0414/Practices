class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Intuition: Use binary search to find the leftmost and rightmost index of the target
        // Time complexity: O(log n)
        // Space complexity: O(1)

        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }

private:
    int binarySearch(vector<int>& nums, int target, bool leftBias) {
        // leftBias: true for searching leftmost index, false for searching rightmost index
        int l = 0, r = nums.size() - 1, i = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (target > nums[m]) {
                l = m + 1;
            } 
            else if (target < nums[m]) {
                r = m - 1;
            } 
            else {
                i = m;
                if (leftBias) {
                    r = m - 1;
                } 
                else {
                    l = m + 1;
                }
            }
        }
        return i;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        nums = [5 7 7 8 8 10]
        Leftmost index: 3
        Rightmost index: 4
        nums[lower_bound(nums.begin(), nums.end(), target) - nums.begin()]: 8
        nums[upper_bound(nums.begin(), nums.end(), target) - nums.begin()]: 10

        nums: 5 7 7 8 8 10 
        target: 6
        nums[lower_bound(nums.begin(), nums.end(), target) - nums.begin()]: 7
        nums[upper_bound(nums.begin(), nums.end(), target) - nums.begin()]: 7
        */
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (left == nums.size() || nums[left] != target) { 
            return {-1, -1};
        }

        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {left, right};
    }
};