/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // DFS
        // TC: O(N)
        // SC: O(N) for storing nums
        if (!head) return nullptr;
        ListNode* curr = head;
        vector<int> nums;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        return DFS(0, nums.size() - 1, nums);
    }

    TreeNode* DFS(int l, int r, vector<int>& nums) { // height of the tree: O(logN)
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
    TreeNode* sortedListToBST(ListNode* head) {
        // TC: O(N*logN) 
        // SC: O(logN) for recursion stack
        if (!head) return nullptr;
        int n = 1;
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
            n++;
        }
        return DFS(0, n - 1, head, n);
    }

    TreeNode* DFS(int l, int r, ListNode* head, const int& n) { // height of the tree: O(logN)
        if (l > r) return nullptr;
        int mid = (l + r) / 2;
        int i = 0;
        ListNode* curr = head;
        while (i != mid) { // find the mid node: O(N)
            curr = curr->next;
            i++;
        }
        TreeNode* root = new TreeNode(curr->val);
        root->left = DFS(l, mid - 1, head, n);
        root->right = DFS(mid + 1, r, head, n);
        return root;
    }
};