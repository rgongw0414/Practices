/*
Morris Traversal
TC: O(n), n nodes in the tree
SC: O(n), for storing each node's values
Intuition: 
Instead of using a stack to simulate the recursive call, we can use the Morris Traversal to achieve O(1) space complexity.
We simulate the LVR recursions by pointing the right child of the rightmost node of the curr->left subtree to curr (from the L to the V in LVR).
  * I.e., rightmost->right = curr, we can go back to V when we finish the L part.
The parent of node the subtree is curr
By curr = curr->right; we either arrive at subtree root's right child (R) or subtree root (curr, V) itself.
By curr = curr->left; we arrive at the left subtree if curr (L)
Steps:
1. Initialize curr as root
2. While curr is not NULL
   If curr does not have left child (i.e., the L part is done)
      a) Print curr’s data
      b) Go to the right, i.e., curr = curr->right
   Else
      a) Make curr as the right child of the rightmost node in curr's left subtree
      b) Go to this left child, i.e., curr = curr->left
*/
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) { // no left child, print the node and go to the right
                nums.push_back(curr->val); // add the current node's value (V) to the result
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
                    nums.push_back(curr->val); // add the current node's value (V) to the result
                    curr = curr->right; // go to the right subtree
                }
            }
        }
        int min_diff = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            min_diff = min(min_diff, abs(nums[i] - nums[i + 1]));
        }
        return min_diff;
    }
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        // Recursive DFS
        // TC:O(n), SC:O(n)
        vector<int> nums; // non-decreasing order
        // The closest number to curr->val is the rightmost/leftmost node in its left/right subtree
        DFS(root, nums);
        int min_diff = INT_MAX;
        for (int i = 0; i < nums.size() - 1; i++) {
            min_diff = min(min_diff, abs(nums[i] - nums[i + 1]));
        }
        return min_diff;
    }

    void DFS(TreeNode* curr, vector<int>& nums) {
        // Traverse the tree in inorder
        if (!curr) return;
        if (!curr->left && !curr->right) {
            nums.push_back(curr->val);
            return;
        }
        DFS(curr->left, nums);
        nums.push_back(curr->val);
        DFS(curr->right, nums);
        return;
    }
};