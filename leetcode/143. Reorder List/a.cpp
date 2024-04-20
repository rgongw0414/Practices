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
    void reorderList(ListNode* head) {

        if (!head->next) {
            return;
        }
        // step 1: find the middle node of the list
        // IDEA: For list [1,2,3,4,5,6,7] we need to return [1,7,2,6,3,5,4]. 
        // We can note that it is actually two lists [1,2,3,4] (list1) and [7,6,5] (list2)
        // *** method 1: find middel by travese the list *** //
        // int listSize = 0;
        // ListNode* curr = head;
        // while (curr) {
        //     listSize++;
        //     stk.push(curr);
        //     curr = curr->next;
        // }

        // *** method 2: trick: two pointers with different move speed *** // 
        // *** NOTE: we can extend this trick to 3 pointers to split the list into 3 parts, and so on. *** //
        ListNode* slow = head; // slow: move with 1 steps/iter
        ListNode* fast = head; // fast: move with 2 steps/iter
        // when iterated through the list, slow and fast would be at middle and the last node respectively.
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2Prev = nullptr;    // the prev node of the second list
        ListNode* list2Curr = slow->next; // the head of the second list
        slow->next = nullptr; // break the original list into two lists
        while (list2Curr) {
            ListNode* list2CurrNext = list2Curr->next;
            list2Curr->next = list2Prev;
            list2Prev = list2Curr;
            list2Curr = list2CurrNext;
        }
        // now the last node of two lists both point to nullptr
        // now list2Prev is the head of the elements to be inserted to original list

        // step 3: merge two lists
        ListNode *head1 = head, *head2 = list2Prev;
        // while (head1 and head2) {
        // #node of list2 <= #node of list1
        while (head2) {
            ListNode* origL1Next = head1->next;
            ListNode* origL2Next = head2->next;
            head1->next = head2;
            head1 = origL1Next; 
            head2->next = head1;
            head2 = origL2Next; 
        }
        // no need to point the merged list to nullptr, because list1 and list2 both already do so, 
        // so once merged, it is a legit list.
    }
};