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
    unordered_map<int, vector<int>> levelMapping; 
    vector<vector<int>> levelOrder(TreeNode* root) {
        // DFS with hash map, TC & SC: O(N)
        // idea: bfs traverse, for each level, push the nodes in next level into queue
        // in each iteration, current queue size is the #node in current level
        // so we pop the queue, and push its children, until it is empty, 
        vector<vector<int>> ans;
        if (!root) return ans;
        dfs(root, 0);
        int lv = 0;
        while (true) {
            if (levelMapping.find(lv) == levelMapping.end()) break;
            ans.push_back(levelMapping[lv]);
            lv++;
        }
        return ans;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        levelMapping[depth].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // iterative BFS, TC: O(N), SC: O(1)
        // idea: bfs traverse, for each level, push the nodes in next level into queue
        // in each iteration, current queue size is the #node in current level
        // so we pop the queue, and push its children, until it is empty, 
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto numOfNodeInCurrLevel = q.size();
            vector<int> nodeInCurrLevelVec;
            while (numOfNodeInCurrLevel--) {
                auto curr = q.front();
                nodeInCurrLevelVec.push_back(curr->val);
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            ans.push_back(nodeInCurrLevelVec);
        }
        return ans;
    }
};