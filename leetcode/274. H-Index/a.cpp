class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Bucket Sort
        // TC=O(N), SC=O(N)
        int n = citations.size();
        vector<int> citationBuckets(n + 1, 0);

        for (int citation : citations) {
            citationBuckets[min(citation, n)]++; // h-index at most equals to n
        }

        int cumulation = 0; // cumulate the number of papers that satisfy the h-index requirement at each iteration
        for (int hIndex = n; hIndex >= 0; hIndex--) {
            // Start from n to 0, so that all the citation nums can be cumulated correctively for different h-index
            // e.g., for h-index of 2, all papers having more than 2 citations must be cumulated
            // if start from 0 to n, there will be papers cumulated into the check of higher h-index
            cumulation += citationBuckets[hIndex]; 
            if (cumulation >= hIndex) {
                return hIndex;
            }
        }
        return 0;        
    }
};

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