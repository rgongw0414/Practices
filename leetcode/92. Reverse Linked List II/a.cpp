/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 left = 1, right = 4, head: 1
 c
 1->2->3->4->5   ->  4->3->2->1->5
 l        r                   h
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0); // helps the cases of left == 1 or only one node in the list
        dummy.next = head; // if left == 1, the list head will be replaced with right, while head is still pointing to left
        // 1. Iterate to left
        ListNode* prev = &dummy;
        ListNode* curr = head;
        for (int i = 0; i < left - 1; ++i) { // iterate (left - 1) nodes to get to left
            prev = curr;
            curr = curr->next;
        }
        // Now: 
        //   prev     curr
        // left_prev  left
        ListNode* sublist_tail = curr;
        ListNode* left_prev = prev;

        // 2. Reverse the sublist
        prev = nullptr;
        for (int i = 0; i < right - left + 1; ++i) { // iterate (right - left + 1) nodes to reverse the sublist
            ListNode* tmp_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp_next;
        }
        // Now: 
        //   prev    curr
        //   right     5
        ListNode* sublist_head = prev;

        // 3. Connect sublist_tail (left_prev) and sublist_head (right) with the reversed sublist
        left_prev->next = sublist_head;
        sublist_tail->next = curr;
        return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 left = 1, right = 4, head: 1
 c
 1->2->3->4->5   ->  4->3->2->1->5
 l        r                   h
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0); // helps the cases of left == 1 or only one node in the list
        dummy.next = head; // if left == 1, the list head will be replaced with right, while head is still pointing to left
        // 1. Iterate to left
        ListNode* prev = &dummy;
        ListNode* curr = head;
        ListNode* left_prev = nullptr, *right_next = nullptr;
        for (int i = 1; i <= right; ++i) { 
            if (i == left) {
                left_prev = prev;
            }
            if (i == right) {
                right_next = curr->next;
                curr->next = nullptr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        ListNode* sublist_head = curr; // right is the head of the reversed sublist
        ListNode* sublist_tail = left_prev->next; // left is the tail of the reversed sublist

        // 2. Reverse the sublist
        prev = nullptr;
        curr = left_prev->next;
        while (curr) { // reverse the sublist
            ListNode* tmp_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp_next;
        }

        // 3. Connect sublist_tail (left_prev) and sublist_head (right) with the reversed sublist
        left_prev->next = sublist_head;
        sublist_tail->next = right_next;
        return dummy.next;
    }
};
    