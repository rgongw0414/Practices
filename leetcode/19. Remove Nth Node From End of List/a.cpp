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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // recursion
        // idea: return the (n+1)-th node of n-th node from tail, and connect (n+1)-th with the (n-1)-th node
        int count = 0;
        ListNode* targetPrev = findPrevNodeOfNth(head, n+1, count);
        ListNode* target;
        if (!targetPrev) {
            // if the returned pointer is nullptr, it means that the node to remove is head node.
            target = head;
            ListNode* newHead = target->next;
            delete target;
            return newHead;
        }
        target = targetPrev->next;
        targetPrev->next = target->next; // skip the target node
        delete target; // prevent memory leak
        return head;
    }

    ListNode* findPrevNodeOfNth(ListNode *curr, int n, int &count) {
        if (!curr) {
            // the tail is reached
            return nullptr;
        }
        ListNode *target = findPrevNodeOfNth(curr->next, n, count); 
        // Note: target is initialized as nullptr, until target found, 
        // if the node we want to delete is head, target will still be nullptr.
        count++; // recursion first, so that in each step from the tail, count is incremented by 1.
        if (count == n) {
            // current node is the target
            target = curr;
        }
        return target;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // slow/fast pointers trick, these two pointers divide the list by two lists
        // idea: keep slow and fast "n nodes" away, 
        // after iteration:
        // slow: n+1 th node from tail, fast: at tail node
        // so we just have to connect slow and the next next node of it.
        ListNode* slow = head, *fast = head;
        for (int i = 0; i < n; i++) {
            // move fast first, so slow and fast are n nodes away.
            fast = fast->next;
        }
        if (!fast) {
            // nullptr is reached, indicating the target is head node,
            // so just return the node next to it.
            return head->next;
        }
        // iterate slow and fast till fast reach tail, so that slow is the n+1 th node from tail after iterating.
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // connect slow and the next next node of it:
        slow->next = slow->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // TC: O(2N), SC: O(1)
        // idea 1: n <= listSize
        // idea 2: if the next-n node is nullptr, then the current node is what we want to delete.
        ListNode* curr = head;
        ListNode* prev = nullptr; // the prev node of curr
        while (1) {
            ListNode* search = curr; // tmp node for searching nth node from tail
            for (int i = 0; i < n; i++) {
                search = search->next;
            }
            if (!search) {
                // the tail is reached, so curr is the nth node from tail.
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (!prev) {
            // prev is initialize with nullptr, so, 
            // it indicates that the target node is head node.
            return head->next;
        }
        prev->next = curr->next;
        return head;
    }
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // idea 1: n <= listSize
        // idea 2: if the next-n node is nullptr, then the current node is what we want to delete.
        ListNode* curr = head;
        ListNode* prev = nullptr; // the prev node of curr
        while (1) {
            ListNode* search = curr; // tmp node for searching nth node from tail
            for (int i = 0; i < n; i++) {
                search = search->next;
            }
            if (!search) {
                // the tail is reached, so curr is the nth node from tail.
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (!prev) {
            // prev is initialize with nullptr, so, 
            // it indicates that the target node is head node.
            return head->next;
        }
        prev->next = curr->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodeVec;
        ListNode* curr = head;
        int listSize = 0;
        while (curr) {
            nodeVec.push_back(curr);
            listSize++;
            curr = curr->next;
        }
        //  0, 1, 2, 3, 4
        // [1, 2, 3, 4, 5]
        // n = 2, listSize = 5
        // idx of 4: 5 - 2
        int nthIdx = listSize - n;
        int nthPrevIdx = nthIdx - 1;
        ListNode* nthNode = nodeVec[nthIdx];
        if (listSize == 1) {
            // only 1 node in the list, so after removal, the list is empty.
            return nullptr;
        }
        if (n == listSize) {
            // node to be removed: first node, so just return the second node.
            return nodeVec[1];
        }
        ListNode* nthPrevNode = nodeVec[nthPrevIdx];
        // connect the prev node and next node
        nthPrevNode->next = nthNode->next;
        return head;
    }
};