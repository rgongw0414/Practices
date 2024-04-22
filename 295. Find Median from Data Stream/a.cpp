class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smallerMaxHeap.empty()) {
            smallerMaxHeap.push(num);
            return;
        }
        if (smallerMaxHeap.size() > largerMinHeap.size()) {
            if (smallerMaxHeap.top() > num) {
                smallerMaxHeap.push(num);
                largerMinHeap.push(smallerMaxHeap.top());
                smallerMaxHeap.pop();
            }
            else {
                largerMinHeap.push(num);
            }
        }
        else {
            if (num > largerMinHeap.top()) {
                largerMinHeap.push(num);
                smallerMaxHeap.push(largerMinHeap.top());
                largerMinHeap.pop();
            }
            else {
                smallerMaxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        double median;
        if (smallerMaxHeap.size() == largerMinHeap.size()) {
            median = ((double)smallerMaxHeap.top() + (double)largerMinHeap.top()) / 2.0;
        }
        else {
            if (smallerMaxHeap.size() > largerMinHeap.size()) {
                median = smallerMaxHeap.top();
            }
            else {
                median = largerMinHeap.top();
            }
        }
        return median;
    }

private:
    priority_queue<int> smallerMaxHeap; // the max of smallerMaxHeap is larger than the min of largerMinHeap
    priority_queue<int, vector<int>, greater<int>> largerMinHeap;  // the min of largerMinHeap is larger than the max of smallerMaxHeap
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
