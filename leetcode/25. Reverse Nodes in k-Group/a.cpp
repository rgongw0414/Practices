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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // iterative method, improved SC: O(1), but less readable code
        // idea: for each group, firstly, reverse it if k nodes available
        // helper nodes: the node before/after each group (nodeBeforeGroup/nodeAfterGroup)
        
        ListNode* dummyHead = new ListNode(0, head); // dummyHead->head
        ListNode* nodeBeforeGroup = dummyHead, *nodeAfterGroup = nullptr;
        while (true) {
            /*
            nodeBeforeGroup->[groupHead->...->kthNode]->nodeAfterGroup
            reverse the nodes in group:
            nodeBeforeGroup->[kthNode->...->groupHead]->nodeAfterGroup
            */
            auto kthNode = getKth(nodeBeforeGroup, k);
            if (!kthNode) {
                // no k nodes available
                break;
            }
            nodeAfterGroup = kthNode->next;

            // reverse the group
            //       prev          curr
            // nodeBeforeGroup->[groupHead->...->kthNode]->nodeAfterGroup
            // ListNode* prev = nullptr;
            ListNode* prev = nodeAfterGroup;  
            // since prev is the next node of curr, so instead of setting prev to nullptr, setting to nodeAfterGroup is better, because it is the next node after reversion.
            ListNode* curr = nodeBeforeGroup->next;
            while (curr != nodeAfterGroup) {
                auto currNext = curr->next;
                curr->next = prev;
                prev = curr;
                curr = currNext;
            }
            auto headOfGroupBeforeReversed = nodeBeforeGroup->next; // head of list before reversed
            nodeBeforeGroup->next = kthNode; // update nodeBeforeGroup->next to the reversed sub-list (group)
            // after reversed, headOfGroupBeforeReversed is the node before next group
            nodeBeforeGroup = headOfGroupBeforeReversed; // update to the node before next group
        }
        auto ansHead = dummyHead->next;
        delete dummyHead;
        return ansHead;
    }

    ListNode* getKth(ListNode* curr, int k) {
        // return the kth node in list, which starting from curr
        // return nullptr, if the remaining number of node is less than k
        int cnt = 0;
        while (curr and cnt < k) {
            curr = curr->next;
            cnt++;
        }
        return curr;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // recursion, this is more understandable than iterative method
        auto curr = head;
        int cnt = 0;
        while (cnt != k) {
            if (!curr) {
                // nullptr is reached, but this last group got less than k nodes, so no need to reverse it.
                return head;
            }
            cnt++;
            curr = curr->next;
        }
        // here we know that there're k nodes in this group, so we have to reverse it.
        cnt = 0;
        curr = head;
        ListNode* prev = nullptr;
        while (true) {
            auto currNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currNext;
            cnt++;
            if (cnt == k) break;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};