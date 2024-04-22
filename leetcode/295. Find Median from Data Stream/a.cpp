#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

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


class MedianFinder {
private:
    vector<int> nums;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        // partial_sort O(N^2): TLE
        int size = nums.size();
        double median;
        // Sort the elements in the range [first, middle) in ascending order
        partial_sort(nums.begin(), nums.begin() + size / 2 + 1, nums.end()); // middle - first = size / 2 + 1; the number sorted number: middle - first
        if (size % 2 == 0) {
            median = ((double)nums[size/2 - 1] + (double)nums[size/2]) / 2;
        }
        else {
            median = (double)nums[size/2];
        }
        return median;
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    vector<int> vec = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    partial_sort(vec.begin(), vec.begin() + 10/2+1, vec.end());
    for (int i : vec) cout << i << ' ';
    cout << endl;

    vec.push_back(-11);
    auto first = vec.begin() + 10 / 2 + 1;
    auto middle = first + 1;
    partial_sort(vec.begin() + 2, middle, vec.end());
    for (int i : vec) cout << i << ' ';
    cout << endl;
}