/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
        two pointers, TC: O(N), SC: O(1)
        this is actually (part of) Floyd Cycle Detection
        full Floyd Cycle Detection: 142.  Linked List Cycle II
        */
        if (!head) return false;
        // idea: 2 pointers with different moving speed, they must meet at some point, if cyclic.
        auto oneStep = head;
        auto twoStep = head; // move one step further

        bool cyclic = false;
        while (twoStep->next and twoStep->next->next) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
            if (oneStep == twoStep) {
                cyclic = true;
                break;
            }
        }
        return cyclic;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // hash set, TC, SC: O(N)
        unordered_set<ListNode*> nodeSet;
        auto curr = head;
        bool cyclic = false;
        while (curr) {
            if (nodeSet.find(curr) != nodeSet.end()) {
                cyclic = true;
                break;
            }
            nodeSet.insert(curr);
            curr = curr->next;
        }
        return cyclic;
    }
};