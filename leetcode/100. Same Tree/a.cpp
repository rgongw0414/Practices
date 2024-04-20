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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // recursion method, TC: O(N), SC: O(k), where k is the depth of tree
        if (!p and !q) {
            // both are the left/right of leaf nodes
            return true;
        }
        if (!p or !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // iterative DFS, TC & SC: O(n);
        stack<TreeNode*> stkP, stkQ;
        stkP.push(p);
        stkQ.push(q);
        bool same = true;
        while (!stkP.empty() and !stkQ.empty()) {
            auto nodeP = stkP.top();
            stkP.pop();
            auto nodeQ = stkQ.top();
            stkQ.pop();
            if (!nodeP and !nodeQ) continue; // both are the left/right ptr of leaf nodes
            if ((!nodeP or !nodeQ) or (nodeP->val != nodeQ->val)) {
                same = false;
                break;
            }
            stkP.push(nodeP->left);
            stkP.push(nodeP->right);
            stkQ.push(nodeQ->left);
            stkQ.push(nodeQ->right);
        }
        if (!stkP.empty() or !stkQ.empty()) same = false;
        return same;
    }
};