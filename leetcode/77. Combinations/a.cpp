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