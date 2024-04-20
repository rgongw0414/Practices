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
    vector<int> rightSideView(TreeNode* root) {
        // iterative BFS, TC & SC: O(N)
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int nodeNumInCurrLevel = q.size();
            bool rightMost= true;
            while (nodeNumInCurrLevel--) {
                auto curr = q.front();
                q.pop();
                if (rightMost) {
                    ans.push_back(curr->val);
                    rightMost = false;
                }
                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        // recursive DFS, TC: O(N), SC: O(logN)
        vector<int> ans;
        if (!root) return ans;
        DFS(root, ans, 0);
        return ans;
    }
    void DFS(TreeNode* curr, vector<int> &ans, int depth) {
        if (!curr) return;
        if (depth == ans.size()) ans.push_back(curr->val); 
        // if ans.size() != depth, it means the right side of this level has benn seen, 
        // i.e. curr is to the left of the right side node.
        DFS(curr->right, ans, depth + 1);
        DFS(curr->left, ans, depth + 1);
    }
};