class Solution {
public:
    int hIndex(vector<int>& citations) {
        // TC=O(nlogn), SC=O(1)
        sort(citations.begin(), citations.end()); // sort the nums in ascending order
        int n = citations.size();
        int max_h = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i + citations[i] - 1 < n) {
                // Since the nums is sorted, the citations[i+offset] must >= citations[i], if (i + citations[i] - 1 < n)
                max_h = max(max_h, citations[i]);
            }
            else {
                // e.g., for citations = [0,1,3,4], h-index = 2
                // The excessive index can be used to correct the h-index
                max_h = max(max_h, (n-1) - i + 1);
            }
        }
        return max_h;
    }
};  

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // TC=O(n^2), SC=O(N)
        int n = citations.size();
        int max_cite = INT_MIN;
        unordered_map<int, int> h_map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= citations[i]; j++) {
                h_map[j]++;
            }
            max_cite = max(max_cite, citations[i]);
        }
        for (int i = max_cite; i >= 0; i--) {
            if (h_map[i] >= i) return i;
        }
        return 0;
    }
};  