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
    ListNode* reverseList(ListNode* head) {        
        if (head == nullptr) return head;
        ListNode* curr = head;
        ListNode* newHead = curr;
        if (curr->next) {
            newHead = reverseList(curr->next);  // the head of reversed sub-LL
            curr->next->next = curr;  //  reverse the current LL
            // curr->next->next originally points to NULL, now update it to curr head to reverse the LL.
        }
        curr->next = nullptr; // set the curr node point to nullptr, which is the tail of the reversed LL
        return newHead;
    }
};