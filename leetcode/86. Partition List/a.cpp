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
d 1->4->3->2->5->2
r  l  c
   l  r  c
d 1->4->3->2->5->2
   l     r  c  
         r  l  c
d 1->4->3->2->5->2
            l  r  c
d 1->4->3->2->5->2->nullptr
               r  l     c

x = 2:
lr c 
d 1->1->nullptr
r  l  c
r    l  c
d 1->1->nullptr<-r
      l
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // TC:O(n), SC:O(1)
        // Two Pointers
        ListNode* l_dummy = new ListNode(777); // l_dummy->next is the head of the left partition
        ListNode* r_dummy = new ListNode(888); // r_dummy->next is the head of the right partition
        ListNode* l_prev = l_dummy, *r_prev = r_dummy, *curr = head;
        // Note that not both l_dummy->next and r_dummy->next are the original head
        // This can easily handle the edge cases, e.g., head = [1], x = 2; head = [2,1,1], x = 2
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
        r_prev->next = nullptr; // end the right partition
        l_prev->next = r_dummy->next; // connect the left partition to the right partition
        return l_dummy->next;
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
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // TC:O(n), SC:O(n)
        // Brute Force
        if (!head) return nullptr;
        
        vector<int> less, greater; // store the values of the nodes
        ListNode* cur = head;

        while (cur) {
            if (cur->val < x) {
                less.push_back(cur->val);
            } else {
                greater.push_back(cur->val);
            }
            cur = cur->next;
        }

        cur = head;
        for (int val : less) { // update the values of the nodes
            cur->val = val;
            cur = cur->next;
        }

        for (int val : greater) {
            cur->val = val;
            cur = cur->next;
        }

        return head;
    }
};