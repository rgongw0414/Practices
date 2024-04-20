class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int product = 1;
      vector<int> ans(nums.size(), 0);      
      ans[0] = 1;
      for (int i = 0; i < nums.size()-1; i++) {
        product *= nums[i];
        ans[i+1] = product;
      }
      product = 1;
      for (int i = nums.size()-1; i > 0; i--) {
        product *= nums[i];
        ans[i-1] *= product;
      }
      return ans;
    }
};