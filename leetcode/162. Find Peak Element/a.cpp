class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // TC: O(logN)
        // SC: O(1)
        // Binary search
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m > 0 && nums[m - 1] > nums[m]) {
                //         l m r
                // nums = [3,2,3,4,...]
                r = m - 1;
            } 
            else if (m < nums.size() - 1 && nums[m] < nums[m + 1]) {
                //               l m r
                // nums = [...,3,2,3,4]
                l = m + 1;
            } 
            else {
                // nums[m-1] < nums[m] < nums[m+1],
                // if m is pointing to the first or the last num, it must be a peak element,
                return m;
            }
        }
        return -1;
    }
};
    
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // TC: O(N)
        // SC: O(1)
        // Linear search
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return i;
        }
        return nums.size() - 1;
    }
};

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // TC: O(logN)
        // SC: O(logN)
        // Recursive Binary search
        return binarySearch(nums, 0, nums.size() - 1);
    }

private:
    int binarySearch(vector<int>& nums, int l, int r) {
        if (l == r) {
            //                 lr      
            // nums = [...,7,8,9]
            // 
            //         lr      
            // nums = [9,8,7,...]
            return l;
        }

        int m = l + (r - l) / 2;
        if (m < nums.size() - 1 && nums[m] < nums[m + 1]) {
            //               m
            // nums = [...,7,8,9]
            return binarySearch(nums, m + 1, r);
        } 
        if (m > 0 && nums[m] < nums[m - 1]) {
            //           m
            // nums = [9,8,7,...]
            return binarySearch(nums, l, m - 1);
        }
        return m;
    }
};