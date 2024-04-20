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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
        slower caused by testbench, in this code, the lists are merged one-by-one, 
        that is the merge order cause the performance poor:
        for (int i = 1; i < lists.size(); i++)
            head = mergeTwoLists(head, lists[i]);
        */
        if (lists.size() == 0 ) return nullptr;
        if (lists.size() == 1 ) return lists[0];
        auto head = lists[0]; // head of the merged list
        // save the merged list at lists[0] and reuse it, but the vector lists still contains other lists when finished
        for (int i = 1; i < lists.size(); i++)
            head = mergeTwoLists(head, lists[i]);
        
        return head;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode* head; // head of merged list
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* curr = head;
        while (l1 and l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (!l1) curr->next = l2;
        if (!l2) curr->next = l1;
        return head;
    }
};