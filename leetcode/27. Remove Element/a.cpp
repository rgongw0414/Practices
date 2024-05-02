class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         // Counter for keeping track of elements != val
        int idxNotVal = 0; // index of the num != val
        // Loop through all the elements of the array
        for (int i = 0; i < nums.size(); i++) {
            // If the element is not val
            if (nums[i] != val) {
                // increse increment if current num != val, increment is also the count of num != val
                nums[idxNotVal++] = nums[i]; // 
            }
            // else {
            //     otherwise, i will iterate all the way to num == val
            // }
        }
        return idxNotVal;
    }
};