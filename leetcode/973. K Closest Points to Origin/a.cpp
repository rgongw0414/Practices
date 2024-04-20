
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // use lambda compare function
        partial_sort(points.begin(), points.begin()+k, points.end(), 
                    [](vector<int> &p1, vector<int> &p2) {
                        return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1]; 
                    }
        );
        vector<vector<int>> ans(points.begin(), points.begin() + k);
        return ans;
    }
};

///////
bool customCompare(vector<int> &p1, vector<int> &p2) {
    return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1]; 
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // partial_sort: with TC of O(N)
        partial_sort(points.begin(), points.begin()+k, points.end(), customCompare);
        int cnt = points.size() - k;
        while (cnt--) {
            points.pop_back();
        }
        return points;
    }
};

///////
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> triples;
        for (auto& p : points)
            triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
        // bottom-up heap construction: O(N)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
        vector<vector<int>> res;
        while (k--) {
            // O(k*logN)
            vector<int> el = pq.top();
            pq.pop();
            res.push_back({el[1], el[2]});
        }
        return res;
    }
};

///////
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // TC: O(N*logk), SC: O(k)
        priority_queue<pair<int, vector<int>>> maxHeap;
        for (auto &p: points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            maxHeap.push({dist, p}); // O(N*logk)
            if (maxHeap.size() > k) maxHeap.pop();
            // the largest (n - k) numbers are popped, so the k smallest numbers will be left in the heap
        }
        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            // O(k*logN)
            auto top = maxHeap.top().second;
            maxHeap.pop();
            ans.push_back(top);
        }
        return ans;
    }
};