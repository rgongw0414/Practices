class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // TLE
        // recursive quick select with TC: O(N), SC: O(logN)
        return quickSelect(nums, nums.size() / 2, 0, nums.size() - 1);
    }

    int quickSelect(vector<int>& nums, int k, int left, int right) {
        // find the kth smallest element in nums
        // Average Case: O(n)
        // 每次僅會在某半邊搜尋，比較次數: n + n/2 + n/4 + n/8 + n/16 + … <= 2n

        // Worst Case: O(n²)，當pivot不斷選到最大/最小的數
        // 可透過Random pivot, Median of three pivot 方式避免worst-case發生
        if (left == right) return nums[left];
        int pivotIdx = partition(nums, left, right);
        if (k == pivotIdx)     return nums[k];
        else if (k < pivotIdx) right = pivotIdx - 1;
        else if (k > pivotIdx) left = pivotIdx + 1;
        return quickSelect(nums, k, left, right);
    }

    int partition(vector<int>& nums, int left, int right) {
        // based on pivot num, partition nums into left (<= pivotNum) and right part (> pivotNum)
        // return the index of the new pivot num
        // defaultly select nums[right] as the pivot num
        int pivotNum = nums[right];
        int i = left; // the nums where index <= i are the number <= pivotNum
        for (int j = left; j < right; j++) {
            /* 
            if (nums[j] > pivotNum) {
                i stopped at where nums[i] > pivotNum, so keep searching for j, where nums[j] <= pivotNum,
                then swap them as the code below:
            }
            */
            if (nums[j] <= pivotNum) {
                // only increse i, so that nums[idx <= i] would <= pivotNum
                swap(nums[i], nums[j]); // since i stopped at where nums[i] <= pivotNum
                i++; 
            }
        }
        swap(nums[i], nums[right]);
        return i; // the new idex of pivotNum
        /*
               i,j        p       nums[j] <= pivotNum
        nums = [1,6,4,2,8,5]    swap(nums[i], nums[j]) -> nums = [1,6,4,2,8,5]    i++; j++;

                 i,j       p      nums[j] > pivotNum
        nums = [1,6,4,2,8,5]    j++; i stopped at where nums[i] > pivotNum, so keep searching for j, where nums[j] <= pivotNum

                  i j     p       nums[j] <= pivotNum               i j   p  
        nums = [1,6,4,2,8,5]    swap(nums[i], nums[j]) -> nums = [1,4,6,2,8,5]    i++; j++;

                    i j   p       nums[j] <= pivotNum                 i j   p  
        nums = [1,4,6,2,8,5]    swap(nums[i], nums[j]) -> nums = [1,4,2,6,8,5]    i++; j++;

                      i j p       nums[j] > pivotNum
        nums = [1,4,2,6,8,5]    j++; i stopped at where nums[i] > pivotNum, so keep searching for j, where nums[j] <= pivotNum

        end of loop:
                      i  j,p
        nums = [1,4,2,6,8,5]    i stopped at where nums[i] > pivotNum, 
        so finally just swap(nums[i], nums[right]);
        nums = [1,4,2,5,8,6]    return i; (pivotNum index)
        */
    }
};