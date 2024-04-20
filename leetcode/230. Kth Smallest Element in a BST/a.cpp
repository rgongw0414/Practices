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
    int kthSmallest(TreeNode* root, int k) {
        // iterative inorder traversal
        vector<int> inorderVisitedNumVec;
        stack<TreeNode*> stk;
        auto curr = root;
        int ans;
        while (true) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            k--;
            if (k == 0) {
                ans = curr->val;
                break;
            }
            curr = curr->right;
        }
        return ans;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // TC: O(n), SC: O(n) (consider a skewed tree)
        int result = 0;
        inorder(root, k, result);
        return result;
    }
private:
    void inorder(TreeNode* root, int& k, int& result) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};