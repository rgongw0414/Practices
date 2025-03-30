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
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Merge sort
        // TC: O(N*logN)
        // SC: O(logN) for recursion stack
        if (!head || !head->next) return head;
        ListNode* left_head = head;
        ListNode* mid = getMid(head); // mid is the tail of the left half
        ListNode* right_head = mid->next;
        mid->next = nullptr;

        left_head = sortList(left_head);
        right_head = sortList(right_head);
        return merge(left_head, right_head);
    }

private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); // for easier handling of the head
        ListNode* curr = &dummy; 
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } 
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;  
        }
        if (list1) curr->next = list1;
        if (list2) curr->next = list2;
        return dummy.next;
    }
};

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

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Slow and fast pointer: For finding the mid node faster
        // TC: O(N*logN)
        // SC: O(logN) for recursion stack
        if (head == nullptr) return nullptr;
        return convertToBST(head, nullptr);
    }

    TreeNode* convertToBST(ListNode* start, ListNode* end) {
        if (start == end) return nullptr;
        ListNode* slow = start;
        ListNode* fast = start;

        while (fast != end && fast->next != end) { // Only half of the sublist is traversed
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* head = new TreeNode(slow->val);
        head->left = convertToBST(start, slow);
        head->right = convertToBST(slow->next, end);
        return head;
    }
};