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
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Traversal
        // TC: O(n), SC: O(1)
        // Intuition: 
        // * Instead of using a stack to simulate the recursive call, we can use the Morris Traversal to achieve O(1) space complexity.
        // * We simulate the LVR recursions by pointing the right child of the rightmost node of the curr->left subtree to curr (from the L to the V in LVR).
        //   * I.e., rightmost->right = curr, we can go back to V when we finish the L part.
        // Steps:
        // 1. Initialize curr as root
        // 2. While curr is not NULL
        //    If curr does not have left child (i.e., the L part is done)
        //       a) Print curr’s data
        //       b) Go to the right, i.e., curr = curr->right
        //    Else
        //       a) Make curr as the right child of the rightmost node in curr's left subtree
        //       b) Go to this left child, i.e., curr = curr->left

        vector<int> res;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) { // no left child, print the node and go to the right
                res.push_back(curr->val); // add the current node's value (V) to the result
                curr = curr->right;
            } 
            else { // curr got left subtree
                TreeNode* rightmost = curr->left; // for the rightmost node in the left subtree
                while (rightmost->right && rightmost->right != curr) { // find the rightmost node in the left subtree
                    // rightmost->right != curr: to avoid infinite loop, 
                    // because some of the rightmosts have been visited; so rightmost->right is curr
                    rightmost = rightmost->right;
                }
                if (!rightmost->right) { // Establish the link b/w the rightmost node and curr
                    rightmost->right = curr;
                    curr = curr->left; // start traversing the left subtree by going to the leftmost node
                } 
                else {
                    rightmost->right = nullptr; // break the link
                    res.push_back(curr->val); // add the current node's value (V) to the result
                    curr = curr->right; // go to the right subtree
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Bottom-up Recursive DFS
        // TC: O(n), SC: O(n)
        vector<int> inorder;
        if (!root) return inorder;
        DFS(inorder, root);
        return inorder;
    }

    void DFS(vector<int>& inorder, TreeNode* curr) {
        if (!curr->left && !curr->right) {
            inorder.push_back(curr->val);
            return;
        }
        if (curr->left) DFS(inorder, curr->left);
        inorder.push_back(curr->val);
        if (curr->right) DFS(inorder, curr->right);
        return;
    }
};

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
    vector<int> inorderTraversal(TreeNode* root) {
        // Iterative DFS (Bottom-up)
        // TC: O(n), SC: O(n)
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) { // skip, if (curr == nullptr)
            while (curr) { // Go to leftmost; skip, if (curr == nullptr)
                stk.push(curr); 
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            res.push_back(curr->val); 
            curr = curr->right; // Go to the right node
        }
        return res;
    }
};