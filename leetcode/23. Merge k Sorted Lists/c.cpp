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
        this is faster because of the testbench, 
        in this code, the first list and last list are merged, and all the way to the middle list, 
        and this method works well on testbench.
        */
        int listsNum = lists.size();
        if (listsNum == 0 ) return nullptr;
        if (listsNum == 1 ) return lists[0];
        int groupNum = listsNum / 2; // take 2 lists as 1 group
        while (groupNum >= 1) {
            for (int i = 0; i < groupNum; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[listsNum - i - 1]); // store the merged list at lists[i]
            }
            // update how many lists remaining
            listsNum = listsNum - groupNum; // e.g. groupNum: 2, indicating 4 lists are merged into 2 lists
            groupNum = listsNum / 2;
            // consider merging l1, l2, l3, l4, l5
            // l1' = merge(l1, l5), l2' = merge(l2, l4), so the remaining lists to be merged are: l1', l2', l3
        }
        return lists[0];
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