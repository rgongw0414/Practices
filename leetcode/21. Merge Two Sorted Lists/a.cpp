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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        
        ListNode* head = nullptr; // the head/tail of the merged list
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* currentTail = head;  // current node discussing, which is the tail node of current merged list
        while (list1 and list2) {
            if (list1->val <= list2->val) {
                currentTail->next = list1;
                list1 = list1->next;
            }
            else {
                currentTail->next = list2;
                list2 = list2->next;
            }
            currentTail = currentTail->next;
        }
        if (!list1) {
            currentTail->next = list2;
        }
        if (!list2) {
            currentTail->next = list1;
        }
        return head;
    }
};

/*
                l1
        list1: [1, 2, 4]
        list2: [1, 3, 4]
                l2
        0. l1 <= l2 -> head = l1, move l1 to next node, curr = head
               c,h l1
        list1: [1, 2, 4]
        list2: [1, 3, 4]
                l2
        1. l1 > l2  -> move curr to l2, move l2 to next node
                h  l1
        list1: [1, 2, 4]
        list2: [1, 3, 4]
                c  l2
        
        2. l1 <= l2 -> move curr to l1, move l1 to next node
                h  c  l1
        list1: [1, 2, 4]
        list2: [1, 3, 4]
                   l2

        3. l1 > l2  -> move curr to l2, move l2 to next node
                h     l1
        list1: [1, 2, 4]
        list2: [1, 3, 4]
                   c  l2
        
        4. l1 <= l2 -> move curr to l1, move l1 to next node, l1 now is nullptr, exit while loop
                h     c l1
        list1: [1, 2, 4]
        list2: [1, 3, 4]
                      l2
        
        5. l1 is nullptr, so move curr to l2, finish the task.
*/