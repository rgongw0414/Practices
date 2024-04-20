class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Time: O(NlogN)
        // Space: O(N)
        if (stones.size() == 1) return stones[0];
        priority_queue<int> maxHeap(stones.begin(), stones.end()); // bottom-up building a heap: O(N)
        while (maxHeap.size() >= 2) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (y != x) maxHeap.push(abs(y-x));
        }
        if (maxHeap.size() == 0) return 0;
        return maxHeap.top();
    }
};