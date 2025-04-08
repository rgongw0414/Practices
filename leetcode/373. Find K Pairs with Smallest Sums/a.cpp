class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // TC=O(k∗log(n1))
        // SC=O(n1)
        vector<vector<int>> resV; // Result vector to store the pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Priority queue to store pairs with smallest sums, sorted by the sum

        // Push the initial pairs into the priority queue
        for (int x : nums1) {
            // These first n1 pairs must be in non-decreasing order beacuse of nums1 and nums2 are already sorted
            // Also, these pairs must be smaller than the following pushed pairs 
            pq.push({x + nums2[0], 0}); // The sum and the index of the second element in nums2
        }

        // Pop the k smallest pairs from the priority queue
        while (k-- && !pq.empty()) {
            int sum = pq.top().first; // Get the smallest sum
            int pos = pq.top().second; // Get the index of the second element in nums2

            resV.push_back({sum - nums2[pos], nums2[pos]}); 
            pq.pop(); 

            // If there are more elements in nums2, push the next pair into the priority queue
            if (pos + 1 < nums2.size()) {
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        }
        return resV; // Return the k smallest pairs
        // Ref: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/?envType=study-plan-v2&envId=top-interview-150
    }
};

class Solution {
private:
    struct Pair {
        int i;
        int j;
    };

public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // head pushing all pairs, TC=O(N^2 logN^2)
        auto cmp = [&](const Pair& a, const Pair& b) {
            return nums1[a.i] + nums2[a.j] < nums1[b.i] + nums2[b.j];
        };
        priority_queue<Pair, vector<Pair>, decltype(cmp)> pq(cmp); // max-heap
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                pq.push({i, j});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        vector<vector<int>> ans(k);
        int idx = 0;
        while (!pq.empty()) {
            ans[idx++] = {nums1[pq.top().i], nums2[pq.top().j]};
            pq.pop();
        }
        return ans;
    }
};