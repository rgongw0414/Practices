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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // recursion, TC: O(N), SC: O(N);
        // SC is O(N) in the worst case of skewed tree
        /*
        preorder (VLR) = [3,9,20,15,7], inorder (LVR) = [9,3,15,20,7]
        idea: root is the first one of preorder, and we can divide the tree into left/right subtree with inorder
        e.g. considering 3 as root, and inorder: [9],3,[15,20,7], 
        [9] is the left subtree, and [15,20,7] is the right subtree,
        though we don't know the exact structure of these subtrees, but there are some other information in preorder.
        In preorder: [3],[9,20,15,7], 3 is the root, and [9,20,15,7] is its children, i.e. left and right subtrees.
        Now we know 3 things:
        1. 3 is root
        2. [9] compose the left subtree, and [15,20,7] compose the right subtree, but we don't know the exact structure of them.
        3. In preorder (VLR): [3],[9,20,15,7], 3 is the root, and [9,20,15,7] is its children, which begins with left subtree, then right subtree. 
        From 2. and 3.:
        preorder: [9,20,15,7] begins with left, then right subtree, also,
        in inorder: [9] compose left subtree, and [15,20,7] compose right subtree.
        9 is the root of left subtree, but we don't know which one of [15,20,7] is the root of right subtree, 
        so we need to check it in next iteration, now look at preorder we can know that 20 is the root.
        */
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
        // preorder: [3,9,20,15,7], inorder: [9,3,15,20,7]
        // root: 3
        if (preStart > preEnd or inStart > inEnd) return nullptr;
        auto root = new TreeNode(preorder[preStart]); // root of this subtree
        int rootInorderIdx; // for dividing inorder into left and right subtrees
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                rootInorderIdx = i; // rootInorderIdx == 1
                break;
            }
        }
        // inorder: [9,3,15,20,7] now can be divided into left: [9], and right: [15,20,7], but the structure in not sure.
        int leftSize = rootInorderIdx - inStart; // leftSize == 1
        int rightSize = inEnd - (rootInorderIdx+1) + 1; // rightSize == 3
        root->left = create(preorder, inorder, 
                            preStart + 1, preStart + leftSize, 
                            inStart, inStart + leftSize - 1); // "- 1" for the sake of indexing
        root->right = create(preorder, inorder, 
                            preStart + leftSize + 1, preStart + leftSize + rightSize, 
                            rootInorderIdx + 1, rootInorderIdx + rightSize);
        return root;
    }
};