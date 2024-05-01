class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Optimized TC: O(2^N) and SC: O(N)
        // Idea: Counts the number of each num (with remainingCandidate);
        //       then checks if there are available num in remainingCandidate.
        unordered_map<int, int> remainingCandidate;
        for (auto& num: candidates) remainingCandidate[num]++;
        vector<int> candidatesWithNoDuplicates;
        for (auto& elem: remainingCandidate) candidatesWithNoDuplicates.push_back(elem.first);

        vector<vector<int>> ans;
        vector<int> combination;
        tryAllCombination(ans, candidatesWithNoDuplicates, 0, target, combination, remainingCandidate);
        return ans;
    }

    void tryAllCombination(vector<vector<int>>& ans, vector<int>& candidates, int i, int target, vector<int>& combination, unordered_map<int, int> &remainingCandidate) {
        if (target < 0 || i >= candidates.size() || remainingCandidate[candidates[i]] < 0) return;
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        combination.push_back(candidates[i]);
        remainingCandidate[candidates[i]]--;
        tryAllCombination(ans, candidates, i, target - candidates[i], combination, remainingCandidate); // try if we can pick one more num 

        combination.pop_back();
        remainingCandidate[candidates[i]]++;
        tryAllCombination(ans, candidates, i + 1, target, combination, remainingCandidate); // try to pick next num
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Two recursions, with TC: O(N * 2^N) and SC of O(N)
        // Idea: Counts the number of each num (remainingCandidate);
        //       skips duplicates with sorting, then checks if current num is available with remainingCandidate.
        sort(candidates.begin(), candidates.end());
        unordered_map<int, int> remainingCandidate;
        for (auto& num: candidates) remainingCandidate[num]++;
        vector<vector<int>> ans;
        vector<int> combination;
        tryAllCombination(ans, candidates, 0, target, combination, remainingCandidate);
        return ans;
    }

    void tryAllCombination(vector<vector<int>>& ans, vector<int>& candidates, int i, int target, vector<int>& combination, unordered_map<int, int> &remainingCandidate) {
        if (target < 0 || i >= candidates.size() || remainingCandidate[candidates[i]] < 0) return;
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++; // skip the duplicates, until next num is not the same anymore.
        combination.push_back(candidates[i]);
        remainingCandidate[candidates[i]]--;
        tryAllCombination(ans, candidates, i, target - candidates[i], combination, remainingCandidate); // try if we can pick one more num 

        combination.pop_back();
        remainingCandidate[candidates[i]]++;
        tryAllCombination(ans, candidates, i + 1, target, combination, remainingCandidate); // try to pick next num
    }
};