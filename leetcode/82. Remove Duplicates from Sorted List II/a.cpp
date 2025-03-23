/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
   p c c c
 1 2 3 3 3 4 5 6
   p c
 1 2 4 5 6
     p c
 1 2 4 5 6
       p c
 1 2 4 5 6
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // TC: O(n), SC: O(1)
        ListNode* dummy = new ListNode(777); // helps the case of only one node in the list
        dummy->next = head;
        ListNode* prev = dummy, *curr = head;
        while (curr) {
            bool duplicated = false;
            while (curr->next && curr->val == curr->next->val) {
                duplicated = true;
                curr = curr->next;
            }
            if (duplicated) prev->next = curr->next;
            else            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};