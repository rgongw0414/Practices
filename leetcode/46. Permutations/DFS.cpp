class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // *** fk swap, use an array instead, to record current used nums in currPerm, much more readable now *** //
        // Total nodes in the tree: N + N*(N-1) + N*(N-1)*(N-2) + ... + N! = O(N!), because N! is the dominant term
        // Recursive DFS with TC: O(N * N!), SC: O(N!)
        // Swaps & DFS in this problem is not intuitive, so use a vector to record currently used nums.
        vector<vector<int>> ans;
        vector<int> currPerm;
        vector<bool> usedNums(nums.size(), false); // current used nums in currPerm
        DFS(ans, nums, currPerm, usedNums);
        return ans;
    }

    void DFS(vector<vector<int>> &ans, vector<int>& nums, vector<int>& currPerm, vector<bool> &usedNums) {
        // TC of this function itselt: O(N)
        if (currPerm.size() == nums.size()) {
            ans.push_back(currPerm);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++) {
            if (!usedNums[i]) {
                currPerm.push_back(nums[i]); // original permutation
                usedNums[i] = true;

                DFS(ans, nums, currPerm, usedNums);  // When all permutations have been exhausted, 
                // return to the current scope and begin backtracking through other permutations.

                currPerm.pop_back(); // resumes to original permutation
                usedNums[i] = false;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Recursive DFS with TC: O(N * N!)
        vector<vector<int>> ans;
        DFS(ans, nums, 0);
        return ans;
    }

    void DFS(vector<vector<int>> &ans, vector<int>& nums, int start) {
        // Total nodes in the tree: N + N*(N-1) + N*(N-1)*(N-2) + ... + N! = O(N!), because N! is the dominant term
        // Swaps & DFS in this problem is not intuitive, it's better to see the graph in github repo.
        // TC of this function itselt: O(N)
        // Overall TC: O(N * N!), SC: O(N!)
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (size_t i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]); // original permutation
            DFS(ans, nums, start + 1);  // When all permutations have been exhausted, 
            // return to the current scope and begin backtracking through other permutations.
            swap(nums[start], nums[i]); // resumes to original permutation
        }
    }
};