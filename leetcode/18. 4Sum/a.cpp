class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;
        sort(nums.begin(), nums.end());
        // set<vector<int>> s; // for filtering duplicated vectors, but costing O(N) of space, however, can be saved with line 11 and 14.
        // O(N^3)
        for (int i=0; i < n-3; i++) {
            if (i > 0 and nums[i] == nums[i-1]) continue; // prevent duplicated quadruplets
            if (target <= 0 and nums[i] > 0) break;
            for (int j=i+1; j < n-2 ; j++) {
                if (j > i+1 and nums[j] == nums[j-1]) continue; // prevent duplicated quadruplets
                if (target-nums[i] <= 0 and nums[j] > 0) break;
                int k = j + 1;
                int l = n - 1;                
                while (k < l) { 
                    // two pointers can save one degree of O(N), 
                    // if use nested two for loops (for k and l), the time complexity will be O(N^4)
                    long a = nums[i], b = nums[j], c = nums[k], d = nums[l]; // prevent from overflow
                    long sum = a+b+c+d;
                    if (sum < target) {
                        k++;
                    }
                    else if (sum > target) {
                        l--;
                    }
                    else {
                        vector<int> vec = {nums[i], nums[j], nums[k], nums[l]};
                        ans.emplace_back(vec);
                        while (k < l && nums[k] == nums[k+1]) k++; // 避免若沒略過重複的nums[k]，找到的vec會重複。
                        k++; // 移動到不重複的數字 e.g. from 22'2'3 to 222'3'
                        // while (k < l && nums[l] == nums[l-1]) l--; // 其實一個while就夠了，因為目標是找到不重複的數字
                        // l--;
                    }
                }
            }
        }
        return ans;
    }
};