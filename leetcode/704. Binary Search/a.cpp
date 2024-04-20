class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int i = 0;
        int j = nums.size() - 1;
        int m = i + (j-i)/2;
        while (i <= j) {
            if (nums[m] == target) {
                ans = m;
                break;
            }
            else if (nums[m] < target) {
                i = m + 1;
            }
            else {
                j = m - 1;
            }
            m = i + (j-i)/2;
        }
        return ans;
    }
};