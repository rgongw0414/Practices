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
    ListNode *detectCycle(ListNode *head) {
        // slow/fast pointers, with math induction
        // Floyd Cycle Detection algorithm
        if (!head) return nullptr;
        // idea: twoStep move 2 times more steps than oneStep; 
        // if there is loop, then the twoStep must "CATCH UP WITH" oneStep at some point
        // oneStep: Dist(head, loopEntry) + loopLen*m + Dist(loopEntry, meetPoint), where m < n;
        // twoStep: Dist(head, loopEntry) + loopLen*n + Dist(loopEntry, meetPoint)
        // d1: Dist(head, loopEntry)
        // d2: Dist(loopEntry, meetPoint)
        // loopLen = d2 + d3 (remaining part of loop)
        /*
                     s,f meet here
        e.g. 3->2->0->4
                ^-----|
            twoStep travel one more loop to catch up with oneStep
            loop entry: 2
            d1 = Dist(3, 2), d2 = Dist(2, 4), d3 = Dist(4, 2)
            oneStep total travel dist (oneTotal) = d1 + d2
            twoStep total travel dist (twoTotal)= d1 + (d2 + d3) + d2
            also, we know that: twoTotal = 2*oneTotal
            hence we can infer that: d1 + (d2 + d3) + d2 = 2 * (d1 + d2)
            so final we got: d1 = d3, which indicating the dist b/w head and entry equals to the dist b/w meet point and entry.
            finally utilizing this property, once the loop is found with these two ptrs, we can just set one of them back to head, 
            and iterate both of them one step each time untill they meet.
        */
        auto oneStep = head;
        auto twoStep = head;
        bool cyclic = false;
        while (twoStep->next and twoStep->next->next) {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
            if (oneStep == twoStep) {
                // loop found
                cyclic = true;
                break;
            }
        }
        if (!cyclic) {
            return nullptr;
        }
        oneStep = head;
        while (oneStep != twoStep) {
            oneStep = oneStep->next;
            twoStep = twoStep->next;
        }
        return oneStep;
    }
};