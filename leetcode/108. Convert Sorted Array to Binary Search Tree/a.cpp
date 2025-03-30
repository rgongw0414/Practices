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
                m
 nums = [-10,-3,0,5,9]
                    m                    m
 nums->left = [-10,-3], nums->right = [5,9]
                      m                          m                        m                         m
 nums->left->left = [-10], nums->left->right = [-3], nums->right->left = [5], nums->right->right = [9], 
 nums->...->left = [], nums->...->right = []
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // TC: O(n) for visiting each node
        // SC: O(logn) for recursion stack
        return DFS(0, nums.size() - 1, nums);
    }

    TreeNode* DFS(int l, int r, vector<int>& nums) {
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = DFS(l, mid - 1, nums);
        root->right = DFS(mid + 1, r, nums);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // TC: O(n*log(n)): Each level of recursion takes O(n) to create a new vector, and there are O(log(n)) levels of recursion.
        // SC: O(n) for left and right vector
        if (nums.empty()) return nullptr;
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};