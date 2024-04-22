class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for (auto const& row: matrix) {
            for (auto const& elem: row) {
                pq.emplace(elem);
                if (pq.size() > k) pq.pop(); // The first eight smallest numbers are kept in pq
            }
        }
        return pq.top();
    }
};