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
 inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 inorder: [9],3,[15,20,7], postorder: [9],[15,7,20],3,end()
           L  V     R                  L      R     V: end() - 1
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // TC: O(N^2), SC: O(N)
        // Ref: 105. Construct Binary Tree from Preorder and Inorder Traversal
        if (inorder.empty() || postorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        int root_in_idx = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> inorder_left(inorder.begin(), inorder.begin() + root_in_idx);
        vector<int> inorder_right(inorder.begin() + root_in_idx + 1, inorder.end());
        vector<int> postorder_left(postorder.begin(), postorder.begin() + root_in_idx);
                                                                                            // 3: end() - 1
        vector<int> postorder_right(postorder.begin() + root_in_idx, postorder.end() - 1); // [9],[15,7,20],3,end()
        root->left = buildTree(inorder_left, postorder_left);
        root->right = buildTree(inorder_right, postorder_right);
        return root;
    }
};