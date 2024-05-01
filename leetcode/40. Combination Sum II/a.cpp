class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // One recursion, with TC: O(N * 2^N) and SC of O(N)
        // Idea: Sort the nums and skip the duplicates in recursions
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        tryAllCombination(ans, candidates, 0, target, combination);
        return ans;
    }

    void tryAllCombination(vector<vector<int>>& ans, vector<int>& candidates, int start, int target, vector<int>& combination) {
        if (target == 0) {
            // this should be checked first to handle the cases of only 1 num in candidates
            ans.push_back(combination);
            return;
        }
        if (target < 0 || start >= candidates.size()) return;

        for (int i = start; i < candidates.size(); i++) { // Looping through candidates contributes to the TC of O(N) in O(N * 2^N) 
            if (i > start && candidates[i - 1] == candidates[i]) continue; // skip the duplicates, because the duplicates have been handled by the left trees.
            combination.push_back(candidates[i]); // choose candidates[i] 
            tryAllCombination(ans, candidates, i + 1, target - candidates[i], combination); // go to next level of the decision tree (refer to the graph under repo)
            combination.pop_back(); // pop candidates[i] for the right subtrees in each level
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Two recursions, with TC: O(N * 2^N) and SC of O(N)
        // NOTE: Dealing with edge cases of index is annoying, so I prefer to use unordered_map to count the number of each num, or use the one recursion method.
        // Idea: Sort the nums and skip the duplicates in recursions
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(), candidates.end()); // *** sort is very useful for skipping the duplicates *** // 
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

        // left subtree recursion
        combination.push_back(candidates[i]);
        tryAllCombination(ans, candidates, i + 1, target - candidates[i], combination); 
        combination.pop_back();

        // Skip the duplicates, because the duplicates have been handled by the left tree, 
        // some combinations in right subtrees will duplicate.
        while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) i++; 
        tryAllCombination(ans, candidates, i + 1, target, combination); // right subtree recursion
    }
};


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
        // *** sort is very useful to skip the duplicates *** // 
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