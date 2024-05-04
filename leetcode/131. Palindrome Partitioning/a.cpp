class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Backtracking
        // Exhausting all partitions takes O(2^(n-1)) = O(2^n), this is because between each pair of adjacent characters, we can choose to partition or not.
        // Check if each subString is a palindrmoe takes O(n)
        // For each partition, combining the substrings, resulting in a string with the same len as string s,
        // so we got overall TC: O(n * 2^n), 
        // and SC: O(n) for recursion call stack and storing each partition.
        vector<vector<string>> ans;
        vector<string> myPartition;
        DFS(s, 0, myPartition, ans);
        return ans;
    }

    bool isPalindrome(string &subString) {
        // two pointer: O(n/2) = O(n)
        if (subString.size() == 0) return false; // empty string is not a plaindrome
        int i = 0;
        int j = subString.size() - 1;
        while (i < j) {
            if (subString[i] != subString[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void DFS(string &s, int start, vector<string> &myPartition, vector<vector<string>> &ans) {
        // Exhausting all partitions takes O(2^(n-1)) = O(2^n), this is because between each pair of adjacent characters, we can choose to partition or not.
        // Function call stack: O(n)
        if (start >= s.size()) {
            ans.push_back(myPartition);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            int subStringLen = i - start + 1;
            string subString = s.substr(start, subStringLen);
            if (isPalindrome(subString)) {
                myPartition.push_back(subString);
                DFS(s, i + 1, myPartition, ans);
                myPartition.pop_back();
            }
        }
    }
};
