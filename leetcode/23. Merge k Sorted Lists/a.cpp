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
        // merge sort, TC: O(n*logk), SC: O(1), 
        // poor performance caused by constantly pop_back() and push_back(), 
        // the reallocation and copying elements under the hood take a lot of time.
        if (lists.size() == 0 ) return nullptr;
        if (lists.size() == 1 ) return lists[0];
        while (lists.size() > 1) {
            ListNode* l1 = lists.back();
            lists.pop_back();
            ListNode* l2;
            if (lists.size() == 0) {
                l2 = nullptr;
            }
            else {
                l2 = lists.back();
                lists.pop_back();
            }
            lists.push_back(mergeTwoLists(l1, l2));
        }
        return lists.back();
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