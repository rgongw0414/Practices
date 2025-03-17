class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // More readable: TC=O(N), SC=O(1)
        // Calculate profit at each time with history low price and max profit.
        int n = prices.size();
        if (n == 0) return 0; 
        int minPrice = prices[0]; // min price so far
        int maxProfit = 0;
        for (int i = 1; i < n; i++) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
                    
            minPrice = min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
};

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