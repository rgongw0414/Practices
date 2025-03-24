/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
x = 3
lr c
d->1->4->3->2->5->2
r  l  c
   l  r  c
d->1->4->3->2->5->2
   l     r  c  
         r  l  c
d->1->4->3->2->5->2
            l  r  c
d->1->4->3->2->5->2->nullptr
               r  l     c

x = 2:
lr c 
d->1->1->nullptr
r  l  c
r    l  c
d->1->1->nullptr<-r
      l
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* l_dummy = new ListNode(777, head);
        ListNode* r_dummy = new ListNode(888, head);
        ListNode* l_prev = l_dummy, *r_prev = r_dummy, *curr = head;
        while (curr) {
            if (curr->val < x) {
                l_prev->next = curr;
                l_prev = curr;
            }
            else {
                r_prev->next = curr;
                r_prev = curr;
            }
            curr = curr->next;
        }
        r_prev->next = nullptr; // important to avoid cycle for edge cases, e.g., x = 2, head = [1]
        l_prev->next = r_dummy->next;
        // r_prev->next = nullptr; // if placed here, it will cause cycle
        return l_dummy->next;
    }
};