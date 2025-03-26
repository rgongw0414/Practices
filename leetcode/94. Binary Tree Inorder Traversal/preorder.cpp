#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // Preorder: VLR
        // Morris Traversal
        // TC: O(n), SC: O(1)
        // The parent of node the subtree is curr
        // By curr = curr->right; we either arrive at subtree root's right child (R) or subtree root (curr, V) itself.
        // By curr = curr->left; we arrive at the left subtree if curr (L)
        vector<int> res;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) { // no left child, print the node and go to the right
                res.push_back(curr->val);
                curr = curr->right; // Arrive at V or R
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
                    res.push_back(curr->val);
                    curr = curr->left; // start traversing the left subtree by going to the leftmost node
                } 
                else {
                    rightmost->right = nullptr; // break the link
                    curr = curr->right; // go to the right subtree
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    /*
    Construct the following tree
        1
         \
          2
         / \
        3   4
             \
              5
    */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    vector<int> res = sol.preorderTraversal(root);
    for (int i : res) cout << i << " "; // Output: 1 2 3 4 5
    cout << endl;
    return 0;
}
