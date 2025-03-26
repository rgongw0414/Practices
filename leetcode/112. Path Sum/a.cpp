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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) {
            if (targetSum - root->val == 0) return true;
            else                            return false;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto iter = q.front();
                q.pop();
                TreeNode* node = iter.first;
                if (node->left) {
                    q.push({node->left, iter.second + node->left->val});
                }
                if (node->right) {
                    q.push({node->right, iter.second + node->right->val});
                }
                if (!node->left && !node->right && iter.second == targetSum) {
                    return true;
                }
            }           
        }
        return false;
    }
};