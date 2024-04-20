/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // recursion, TC and SC: O(logN)
        /*
        Given a "Binary Search Tree", indicating: p->val <= ancestor->val  <= q->val,
        where either:
        1. p->val <= root->val  <= q->val, 
        2. root->val  <= p->val, q->val, or
        3. p->val, q->val <= root->val is satisfied.
        All Node->val are "UNIQUE"
        p != q
        #nodes in the tree >= 2
        p and q will exist in the BST: p and q != nullptr
        */
        if (!root) return nullptr; // in this problem, LCA must exist in the BST, so this line is actually trivial
        if (p->val < root->val && q->val < root->val) {
            /* LCA is in the left half of the BST, so move current node to the left half subtree
                curr
                 /
                p,q
            */
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > root->val && q->val > root->val) {
            /* LCA is in the right half of the BST, so move current node to the right half subtree
                curr
                \
                p,q
            */
            return lowestCommonAncestor(root->right, p, q);
        }
        /* curr must be the LCA here
        else {
            return root;
            1.         2.       3.         4.       5. 
               curr        p       p          q        q
                /\        /         \        /          \
              ... ...    q           q      p            p
              /     \
             p       q       
        }
        */
        return root; // LCA found, which is the current node
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // make good use of BST properties, TC: O(logN), SC: O(1)
        /*
        Given a "Binary Search Tree", indicating: p->val <= ancestor->val  <= q->val,
        where either:
        1. p->val <= root->val  <= q->val, 
        2. root->val  <= p->val, q->val, or
        3. p->val, q->val <= root->val is satisfied.
        All Node->val are "UNIQUE"
        p != q
        #nodes in the tree >= 2
        p and q will exist in the BST: p and q != nullptr
        */
        auto curr = root;
        TreeNode* LCA = nullptr;
        while (true) {
            // utilizing the properties of BST
            if (p->val < curr->val and q->val < curr->val) {
                /* LCA is in the left half of the BST
                 curr
                  /
                 p,q
                */
                curr = curr->left;
            }
            else if (curr->val < p->val and curr->val < q->val) {
                /* LCA is in the right half of the BST
                 curr
                   \
                   p,q
                */
                curr = curr->right;
            }
            else {
                /* curr must be the LCA here
                either:
                1.         2.       3.         4.       5. 
                  curr        p         p          q        q
                   /\        /           \        /          \
                ...  ...    q              q     p            p
                 /     \
                p       q       
                */
                LCA = curr;
                break;
            }
        }
        return LCA;
    }
};