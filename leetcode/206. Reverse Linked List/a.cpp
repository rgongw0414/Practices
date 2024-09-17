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
// Recursive solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {        
        // return the head of the reversed LL
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

// Iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {        
        if (head == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        // prev (nullptr) -> curr -> tmp (aka curr->next)
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};