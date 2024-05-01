class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // DFS backtracking with TC: (N * 2^N), and SC: O(N)
        // Idea: All the duplicates are discuessed in each left subtree, so we can skip the duplicates in each right subtree
        // If looked into the left subtree and the right subtree of a node, we can find that the right ones must be subsets of the left ones (subsets in left subtree)
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end()); // sort nums s.t. we can skip the duplicates in each right subtree
        DFS(ans, nums, subset, 0);
        return ans;
    }

    void DFS(vector<vector<int>>& ans, vector<int>& nums, vector<int>& subset, int idx) {
        if (idx == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        DFS(ans, nums, subset, idx + 1);
        
        subset.pop_back();
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) idx++;
        DFS(ans, nums, subset, idx + 1);
    }
};