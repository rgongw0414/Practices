class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // TC: O(s.size() * wordDict.size() * w.size())
        // SC: O(s.size())
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true; // if reached here, it means prev word is breakable by dict
        for (int i = s.size() - 1; i >= 0; i--) { // do it in reverse, so that we can skip the pos visited before 
            for (const string& w : wordDict) { 
                if (i + w.size() <= s.size() && s.substr(i, w.size()) == w) { 
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) break; // the current word is breakable, no need to check the chars after that 
            }
        }
        return dp[0];
    }
};

// TODO: Recursion + Memoization