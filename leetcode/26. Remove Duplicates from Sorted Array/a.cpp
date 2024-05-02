class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // More readable, and SC: O(1)
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // SC: O(1), but this is less readable
        // Similar to "27. Remove Element", set target val to the num pointing by j
        int val = nums[0]; // target val
        int i = 0, j = 0;
        while (i < nums.size()) {
            if (nums[i] != val) {
                j++;
                nums[j] = nums[i];
                val = nums[i];
            }
            i++;
        }
        return j + 1;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Use bool vector to record used number, SC: O(201)
        vector<bool> numsExist(201, false); 
        // idx:    0 ~ 99 <-> num: -100 ~ -1
        // idx:       100 <-> num: 0
        // idx: 101 ~ 200 <-> num: 1 ~ 100
        // num + 100 = idx
        // idx - 100 = num
        for (int i = 0; i < nums.size(); i++) {
            numsExist[nums[i] + 100] = true;
        }
        int j = 0;
        for (int idx = 0; idx < 201; idx++) {
            if (numsExist[idx]) {
                nums[j] = idx - 100;
                j++;
            }
        }
        return j;
    }
};