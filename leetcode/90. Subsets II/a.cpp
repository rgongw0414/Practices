class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // TC: O(N * 2^N), SC: O(2^N)
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // sort first, in order to skip the duplicates
        for (int mask = 0; mask < (1 << nums.size()); ++mask) { // 1 << nums.size() == 2 ** n
            bitset<10> bits(mask);
            vector<int> subset;

            // Check each bit of the mask
            bool validSubset = true;
            for (int i = 0; i < nums.size(); ++i) {
                if (bits[i]) {
                    // Skip duplicate elements
                    if (i > 0 && nums[i] == nums[i - 1] && !bits[i - 1]) {
                        validSubset = false;
                        break;
                    }
                    subset.push_back(nums[i]);
                }
            }

            // Add the valid subset to the result
            if (validSubset) {
                result.push_back(subset);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // DFS backtracking with TC: (N * 2^N), and SC: O(N) (excluding the result vector, otherwise SC: O(N * 2^N))
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
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) idx++; // contributes O(N) to the overall TC
        DFS(ans, nums, subset, idx + 1);
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Worst performance, but the most understandable solution
        // Bit manipulation with TC: O(N! * (N * log(N))), and SC: O(N! * N)
        int n = nums.size();
        set<multiset<int>> subsetSet; // use set to eliminate the duplicated subsets
        for (int i = 0; i < (1 << n); i++) {
            // O(N! * N * log(N))
            multiset<int> subset;
            for (int j = 0; j < n; j++) {
                // O(N * log(N))
                if (i & (1 << j)) {
                    // multiset.insert: automatically sorts nums[j] when inserted, takes O(log(nums.size()))
                    subset.insert(nums[j]); 
                }
            }
            subsetSet.insert(subset);
        }
        vector<vector<int>> res;
        for (auto &subset: subsetSet) {
            vector<int> set_to_vec{subset.begin(), subset.end()};
            res.push_back(set_to_vec);
        }
        return res;
    }
};