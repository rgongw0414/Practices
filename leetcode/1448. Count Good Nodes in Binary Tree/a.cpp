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
    int goodNodes(TreeNode* root) {
        // iterative BFS
        // good: curr->val > max val in the path
        int good = 0;
        queue<pair<TreeNode*, int>> q; // pair: (curr node, maxValueInPath), where maxValueInPath not including curr->val
        q.push({root, root->val});
        while (!q.empty()) {
            int numOfNodeThisLevel = q.size();
            while (numOfNodeThisLevel--) {
                auto curr = q.front().first;
                auto maxValueInPath = q.front().second;
                q.pop();
                if (curr->val >= maxValueInPath) {
                    maxValueInPath = max(maxValueInPath, curr->val);
                    good++;
                }
                if (curr->left) q.push({curr->left, maxValueInPath});
                if (curr->right) q.push({curr->right, maxValueInPath});
            }
        }
        return good;
    }
};


class Solution {
public:
    int goodNodes(TreeNode* root) {
        // recursive DFS
        // good: curr->val > max val in the path
        int good = 0;
        // good: number of good nodes in the tree
        int maxInPath = root->val;
        findGoodNodes(root, good, maxInPath);
        return good;
    }
    void findGoodNodes(TreeNode* curr, int &good, int maxInPath) {
        // maxInPath: max value from root to current node (excluding curr)
        if (!curr) return;
        if (curr->val >= maxInPath) good++;
        maxInPath = max(maxInPath, curr->val);
        findGoodNodes(curr->left, good, maxInPath);
        findGoodNodes(curr->right, good, maxInPath);
    }
};