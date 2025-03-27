/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        // Recursive DFS
        // TC: O(n), SC: O(n)
        int ans = 0;
        string str = "";
        DFS(root, ans, str);
        return ans;
    }

    void DFS(TreeNode* curr, int& ans, string& str) {
        if (!curr) return;
        char ch = '0' + curr->val;
        str.push_back(ch);
        if (!curr->left && !curr->right) {
            ans += stoi(str);
            str.pop_back();
            return;
        }
        DFS(curr->left, ans, str);
        DFS(curr->right, ans, str);
        str.pop_back();
        return;
    }
};