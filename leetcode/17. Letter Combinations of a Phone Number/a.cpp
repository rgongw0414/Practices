class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Backtracking
        // Key idea of backtracking: 
        //  1. Draw the tree of all possibilities wrt the problem, 
        //  2. Figure out how to push, DFS, and pop each node (start backtracking other possibilities).
        // TC: O(4 * (1 + 4 + 4^2 + ... + 4^N)) = O(4 * (4^N - 1)/(4 - 1)) = O(4^N)
        // SC: O(N), where N: digits.size(), for storing each string for ans, and also for recursion function calls stack.
        unordered_map<char, string> numMap = {{'2', "abc"}, {'3', "def"}, 
                                        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, 
                                        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;
        string currStr = "";
        if (digits.size() == 0) return ans;
        DFS(ans, digits, 0, currStr, numMap);
        return ans;
    }

    void DFS(vector<string>& ans, string& digits, int idx, string& currStr, unordered_map<char, string>& numMap) {
        // TC: O(4) for traversing through letters
        // SC: O(N), where N: digits.size(), for storing each string for ans, and also for recursion function calls stack.
        if (idx >= digits.size()) {
            ans.push_back(currStr);
            return;
        }
        const char digit = digits[idx];
        const string letters = numMap[digit];
        for (const char& letter: letters) {
            // TC: O(4)
            currStr.push_back(letter);
            DFS(ans, digits, idx + 1, currStr, numMap);
            currStr.pop_back();
        }
    }
};