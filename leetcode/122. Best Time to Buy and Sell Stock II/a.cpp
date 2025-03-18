class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Two pointers
        // Time complexity: O(n)
        // Space complexity: O(1)
        int l = 0, r = 1; // l: buy at time l, r: sell at time r
        int total_profit = 0;
        while (r < prices.size()) {
            if (prices[l] <= prices[r]) {
                total_profit += prices[r] - prices[l];
                l = r; // sell at time r, so update l to r (buy another one at time r)
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
        return total_profit;
    }
};