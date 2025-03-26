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
/*       c
         1                                      1                                1
     lt / \    connect lt to c->right            \ c   connect lt to c->right     \
       2   5   --------------------->             2    --------------------->      2
      / \   \                                 lt / \                                \ c
     3   4   6                                  3   4                                3
          lt                                         \                                \ c
                                                      5                                4
                                                       \                                \ c
                                                        6                                5
                                                                                          \ c
                                                                                           6
* Ref: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/solutions/1067000/c-both-recursive-iterative-solution        
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        // With the concept of Morris Traversal
        // TC: O(n), SC: O(1)
        // Intuition:
        // 1. For each node, if it has a left child, then find the rightmost node of the left subtree
        // 2. Connect the rightmost node of the left subtree to the right child of the current node
        // 3. Move the left child to the right child
        // 4. Repeat the above steps until the current node is nullptr
        if (!root) return;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                TreeNode* l_tree = curr->left; // For finding the rightmost node of the left subtree
                while (l_tree->right) {
                    l_tree = l_tree->right;
                }
                l_tree->right = curr->right; // Connect the rightmost node of the left subtree to the right child of the current node
                curr->right = curr->left; // Flatten the left child to the right child
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // Recursive DFS (bottom-up pre-order traversal)
        // TC: O(n), SC: O(n)
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left){ // if got left child, then insert the left child b/w curr and the right child
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = nullptr;
            while (root->right) root = root->right; // go to the rightmost node of the left subtree
            root->right = right; // insert the right child to the rightmost node of the left subtree
        }
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // Iterative DFS (top-down)
        // TC: O(n), SC: O(n)
        if (!root) return;
        stack<TreeNode*> stk;
        stk.push(root);
        while (true) {
            TreeNode* curr = stk.top();
            stk.pop();

            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
            if (stk.empty()) break;
            TreeNode* next = stk.top();
            curr->left = nullptr;
            curr->right = next;
        }
        return;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        // Recursive DFS (bottom-up) with reversed pre-order traversal (RLV)
        // TC: O(n), SC: O(n)
        dfs(root, nullptr);
    }

private:
    TreeNode* dfs(TreeNode* curr, TreeNode* prev) {
        // We are doing a reversed pre-order traversal (RLV)
        // prev: the previous node in the reversed pre-order traversal
        if (!curr) return prev; // Base case: return the last processed node
        prev = dfs(curr->right, prev);
        prev = dfs(curr->left, prev);

        curr->right = prev;  // Connect the current node's right to the previous node
        curr->left = nullptr; 
        return curr; // Return the current node as the "new previous"
    }
};
    