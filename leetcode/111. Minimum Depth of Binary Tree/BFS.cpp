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
    int minDepth(TreeNode* root) {
        // BFS
        if (!root) return 0; // empty tree
        if (!root->left && !root->right) return 1; // only one node in the tree
        queue<TreeNode*> q;
        q.push(root);
        int minDepth = INT_MAX;
        int currDepth = 1;
        while (!q.empty()) {
            int numOfNodeThisLevel = q.size();
            while (numOfNodeThisLevel--) {
                auto currNode = q.front();
                q.pop();
                if (!currNode->left && !currNode->right) {
                    // this is a left node
                    minDepth = min(minDepth, currDepth);
                }
                if (currNode->left) q.push(currNode->left);
                if (currNode->right) q.push(currNode->right);
            }
            currDepth++;
        }
        return minDepth;
    }
};