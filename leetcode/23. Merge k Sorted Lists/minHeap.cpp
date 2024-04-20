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
        // min heap, TC: (n*logn), SC: O(n)
        if (lists.size() == 0) return nullptr;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto list: lists) {
            ListNode* curr = list;
            while (curr) {
                minHeap.push(curr->val);
                curr = curr->next;
            }
        }
        if (minHeap.empty()) {
            return nullptr;
        }
        ListNode* head = new ListNode(minHeap.top());
        minHeap.pop();
        ListNode* curr = head;
        while (!minHeap.empty()) {
            curr->next = new ListNode(minHeap.top());
            minHeap.pop();
            curr = curr->next;
        }
        return head;
    }
};