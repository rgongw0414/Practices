class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // two pointers: TC=O(N), SC=O(1)
        int l = 0, r = 1;
        int ans = 0;
        while (r < prices.size()) {
            if (prices[l] <= prices[r]) {
                ans = max(ans, prices[r] - prices[l]);
            }
            else {
                // Can't sell because prices[l] > prices[r],
                // so we have to find prices[tmp] > prices[l], where prices[l] > prices[r].
                // Consider these two, we get: prices[tmp] - prices[r] > prices[tmp] - prices[l], 
                // so update left pointer l with r.
                l = r;
            }
            r++;
        }
        return ans;
    }
};