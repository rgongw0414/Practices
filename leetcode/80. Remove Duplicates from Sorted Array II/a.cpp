class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // This problem is tricky!!!
        // Note that nums are sorted in non-decreasing order
        // nums[0] and nums[1] must be legal, so starts from idex 2
        // slow: *** The num has to be modified, the nums before slow are legal. ***
        // fast: nums[slow - 2] and nums[slow - 1] must not equl to nums[fast]
        // if (nums[fast] == nums[slow - 2]), it means nums[fast] is a duplicate of nums[slow - 2] and nums[slow - 1],
        // so we have to move fast to find a num not a duplicate of it.
        
        // Because nums before nums[slow] are legal, so if nums[fast] != nums[slow - 2], 
        // indicating that nums[fast] is not a duplicate of nums[slow - 2] and nums[slow - 1],
        // hence nums[slow] can be modified with nums[fast].
        if (nums.size() <= 2) return nums.size();
        int slow = 2, fast = 2;
        for (fast; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};