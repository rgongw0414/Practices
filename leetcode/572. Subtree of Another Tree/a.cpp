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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // recursion;
        // TODO: use preorder and inorder traversal to check whether they are the same subtree
        if (!root) {
            return false;
        }
        if (isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode* node1, TreeNode* node2) {
        // node1/node2: node of the first/second subtree
        if (!node1 and !node2) return true;
        if (!node1 or !node2) return false;
        if (node1->val != node2->val) return false;
        return isSame(node1->left, node2->left) and isSame(node1->right, node2->right);
    }
};