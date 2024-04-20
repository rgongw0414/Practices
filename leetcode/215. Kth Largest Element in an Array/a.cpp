class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // partial sort, nth_element
        // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

/////
class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int& k) {
        // avg: O(N)
        // worst: O(N^2)
        int pivot = nums[right]; // take the rightmost num as pivot
        int p_idx = left; // resulting pivot idx, which the nums left to pivot are less than it, similarly for nums right to pivot.
        for (int i = left; i < right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[p_idx]);
                p_idx++;
            }
        }
        swap(nums[right], nums[p_idx]);
        if (k < p_idx) {
            return quickSelect(nums, left, p_idx-1, k);
        }
        else if (k > p_idx) {
            return quickSelect(nums, p_idx+1, right, k);
        }
        else {
            return nums[p_idx];
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        // TC: O(n) on averaged case
        k = nums.size() - k; // idx of the k-th largest num        
        return quickSelect(nums, 0, nums.size()-1, k);
    }
};

/////
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // TC: O(N*logN), built-in sorting
        sort(nums.begin(), nums.end());
        auto it = nums.rbegin();
        it = it + (k-1);
        return(*it);
    }
};

/////
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // TC: O(N*logk), min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto const& n: nums) {
            pq.emplace(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};