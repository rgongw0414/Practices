class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        // stk.push({temperatures[0], 0});
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            // O(2N): push and pop for each elem
            while (!stk.empty() and stk.top().first < temperatures[i]) {
                int idx = stk.top().second;
                ans[idx] = i - idx;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return ans;
    }
};