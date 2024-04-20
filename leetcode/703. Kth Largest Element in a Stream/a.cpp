class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        // TC: O(N*logk), SC: O(k)
        // N integers, each takes at most O(logk) to heapify minHeap
        for (auto &n: nums) {
            this->minHeap.push(n); // only the number larger than the min number in minHeap will be inserted
            if (minHeap.size() > k) minHeap.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        this->minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */