class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O((n^2))
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;        
        for (int i = 0; i < nums.size()-1-1; i++) {
            if (i > 0 and nums[i] == nums[i-1]) continue; // skip the discussed numbers
            if (nums[i] > 0) break;
            // a + b + c = 0 -> b + c = -a = target
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) { // target = 0 (like the target in twoSum of sorted vector<int> nums)
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    ans.emplace_back(vec);
                    while (j < k && nums[j+1] == nums[j]) j++; // if nums[j+1] == nums[j], we will find a duplicated triplet
                    j++;
                    // while (j < k && nums[k-1] == nums[k]) k--; // 其實一個while就夠了，因為目標是找到不重複的數字
                    // k--;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O((n^2)*logn)
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // i: idx for target (as the target in twoSum of sorted vector<int> nums)
        // j: idx for left ptr
        // k: idx for right ptr
        int target = 0;
        for (int i = 0; i < nums.size()-1-1; i++) {
            if (i > 0 and nums[i] == nums[i-1]) continue; // the target has benn discussed
            if (nums[i] > 0) break;
            // a + b + c = 0 -> b + c = -a = target
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    j++;
                }
                else if (sum > target) {
                    k--;
                }
                else {
                    vector<int> vec = {nums[i], nums[j], nums[k]};
                    ans.emplace_back(vec);
                    while (j < k && nums[j+1] == nums[j]) j++; // if nums[j+1] == nums[j], we will find a duplicated triplet
                    j++;
                    while (j < k && nums[k-1] == nums[k]) k--; // similarly for k.
                    k--;
                }
            }
        }
        return ans;
    }
};