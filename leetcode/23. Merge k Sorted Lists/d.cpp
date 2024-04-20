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
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // custom ListNode* compare function for minHeap, but it takes more memory than int minHeap
        if (lists.size() == 0) return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;
        for (ListNode* list: lists) {
            ListNode* curr = list;
            while (curr) {
                minHeap.push(curr);
                curr = curr->next;
            }
        }
        if (minHeap.empty()) {
            return nullptr;
        }
        ListNode* head = minHeap.top();
        minHeap.pop();
        ListNode* curr = head;
        while (!minHeap.empty()) {
            curr->next = minHeap.top();
            minHeap.pop();
            curr = curr->next;
        }
        curr->next = nullptr;
        return head;
    }
};