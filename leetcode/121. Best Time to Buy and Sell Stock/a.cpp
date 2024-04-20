class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int ans = 0;
        while (r < prices.size()) {
            if (prices[l] <= prices[r]) {
                ans = max(ans, prices[r] - prices[l]);
            }
            else {
                // can't sell, because prices[l] > prices[r],
                // which also means that a lower price is found at r, so update left pointer l with r.
                l = r;
            }
            r++;
        }
        return ans;
    }
};