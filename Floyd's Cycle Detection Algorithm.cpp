class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /* 
        Problem: LeetCode 287. Find the Duplicate Number
        Algorithm: Floyd's Cycle Detection Algorithm
        Step 1: Turning array into linked-list representation:
            Idea:
                Each array num can be considered as: 
                    1: Current node's val, 
                    2: The next pointer to next node (except for head 0, we access the real num with 0), 
                       i.e. taking num as index to next node; currNode/currNum: currNum; nextNode/nextNum = nums[currNum]
                    e.g.  idx: [0,1,2,3,4]
                         nums: [1,3,4,2,2]
                         list: 0->1->3->2->4
                                        ^--|
                We take 0 as the dummy head for our list, and access our first node 1 with it.
        Step 2: Apply the algorithm
          Observation: The loop entry is pointed by two nodes, indicating it is pointed by nums[3] and nums[4], 
                       i.e. nums[3] equals to nums[4], because they are used as index to next node, 
                       so the duplicate is nums[3] and nums[4]
        */
        int slow = 0;
        int fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                // slow and fast are intersected, i.e. fast out loop slow and catch up with slow.
                break;
            }
        }
        int slow2 = 0;
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};