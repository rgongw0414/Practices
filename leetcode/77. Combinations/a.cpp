class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // DFS Backtracking
        // Time complexity: O(C(n, k)) = O(n!/(k!(n-k)!))
        // Space complexity: O(k)
        vector<vector<int>> ans;
        vector<int> comb;
        DFS(ans, comb, 1, n, k);
        return ans;
    }

    void DFS(vector<vector<int>>& ans, vector<int>& comb, int i_start, int& n, int& k) {
        if (comb.size() == k) {
            ans.push_back(comb);
            return;
        }
        for (int i = i_start; i <= n; i++) {
            comb.push_back(i);
            DFS(ans, comb, i + 1, n, k);
            comb.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // Bit Manipulation
        // Intuition: There are 2^n possible combinations of n elements. We can represent each combination as a bitmask of length n, where each bit represents whether the corresponding element is included in the combination or not.
        // For example, for n = 4, the bitmask 1010 represents the combination {2, 4}.
        // Time complexity: O(n * 2^n)
        // Space complexity: O(n * 2^n)
        // Note: This approach generates all possible combinations, including those with fewer than k elements.
        // To filter out the combinations with exactly k elements, we can check the size of each combination and only add it to the result if it has size k.
        // This approach is not optimal for large n, but it is a good exercise in bit manipulation.
        // Note: This approach is not optimal for large n, but it is a good exercise in bit manipulation.
        vector<vector<int>> res;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> comb;
            for (int bit = 0; bit < n; ++bit) {
                if (mask & (1 << bit)) { // Check each bit in the mask
                    comb.push_back(bit + 1);
                }
            }
            if (comb.size() == k) {
                res.push_back(comb);
            }
        }
        return res;
    }
};