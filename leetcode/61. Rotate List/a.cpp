/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 k = 2, new_head = 4, new_tail = 3 (prev of new_head)
 1->2->3->4->5
 h    nt nh  t
 k = 4, new_head = 2, new_tail = 1 (prev of new_head, also original head!)
 1->2->3->4->5  -> 2->3->4->5->1
nt nh        t      
 h   
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // TC:O(n), SC:O(1)
        // Key Points: 
        // 1. The k-th node from tail is the new head, and the prev of it is the new tail
        // Method: 
        // 1. Find tail and the k-th node from tail, we got [head, ..., new_tail, new_head, ..., tail]
        // 2. Connect tail to head and new_tail to nullptr, then point new_tail to nullptr
        // 3. Return new_head
        if (head == nullptr) return nullptr;
        int list_len = 0;
        ListNode* curr = head, *prev = nullptr, *tail = nullptr; // tail is the original tail
        ListNode* new_head = nullptr, *new_tail = nullptr; // new_tail is the prev of new_head
        while (curr) { 
            if (!curr->next) tail = curr;
            curr = curr->next;
            list_len++;
        }
        k = k % list_len;
        if (k == 0) return head;
        curr = head;
        int i = 1;
        while (curr) { // iterating to the k-th node
            if (i == list_len - k + 1) {
                new_head = curr;
                new_tail = prev;
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }
        tail->next = head;
        new_tail->next = nullptr;
        return new_head;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Fewer variables: Iterates to the prev of the k-th node from tail
        // TC:O(n), SC:O(1)
        // Key Points: 
        // 1. The k-th node from tail is the new head, and the prev of it is the new tail
        // Method: 
        // 1. Find tail and the (k+1)-th node from tail, we got [head, ..., new_tail, new_head, ..., tail]
        // 2. Connect tail to head and new_tail to nullptr, then point new_tail to nullptr
        // 3. Return new_head
        if (!head) return nullptr;

        ListNode* curr = head;
        int list_len = 1;
        while (curr->next) { // Iterate curr from head to tail
            curr = curr->next;
            list_len++;
        }
        // Now curr points to tail
        k %= list_len;
        if (k == 0) return head;
        curr->next = head; // Points tail to the original head
        
        curr = head;
        int i = 1;
        while (i < list_len - k) { // iterating to the prev node of the k-th node from tail
            curr = curr->next;
            i++;
        }
        // Now curr is points to the new tail (the prev node of the k-th node from tail)
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};