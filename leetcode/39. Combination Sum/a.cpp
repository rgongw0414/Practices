class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // only one recursion, with TC of O(2^N)
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> combination;
        tryAllCombination(ans, candidates, 0, target, combination);
        return ans;
    }

    void tryAllCombination(vector<vector<int>>& ans, vector<int>& candidates, int currIdx, int target, vector<int>& combination) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        for (int i = currIdx; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            tryAllCombination(ans, candidates, i, target - candidates[i], combination); // try to pick next num
            combination.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // two recursion, with TC of O(2^N) and SC of O(N)
        vector<vector<int>> ans;
        vector<int> combination;
        tryAllCombination(ans, candidates, 0, target, combination);
        return ans;
    }

    void tryAllCombination(vector<vector<int>>& ans, vector<int>& candidates, int i, int target, vector<int>& combination) {
        if (target == 0) {
            // this should be checked first to handle the cases of only 1 num in candidates
            ans.push_back(combination);
            return;
        }
        if (target < 0 || i >= candidates.size()) return;
        combination.push_back(candidates[i]);
        tryAllCombination(ans, candidates, i, target - candidates[i], combination); // try if we can pick one more num 
        combination.pop_back();
        tryAllCombination(ans, candidates, i + 1, target, combination); // try to pick next num
    }
};