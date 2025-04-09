class Solution {
public:
    string longestPalindrome(string s) {
        // Two pointers
        // TC: O(n^2)
        // SC: O(1)
        // Idea: Take each char as the palindrome center, and expand to left and right
        int p_idx = 0; // index of the palindrome starting pos
        int p_len = 0;
        for (int i = 0; i < s.size(); i++) { 
            int L = i, R = i; // odd-len panlindrom
            while (L >= 0 && R < s.size() && s[L] == s[R]) {
                if (R - L + 1 > p_len) {
                    p_idx = L;
                    p_len = R - L + 1;
                }
                L--;
                R++;
            }

            L = i, R = i + 1; // even-len panlindrom
            while (L >= 0 && R < s.size() && s[L] == s[R]) {
                if (R - L + 1 > p_len) {
                    p_idx = L;
                    p_len = R - L + 1;
                }
                L--;
                R++;
            }
        }
        return s.substr(p_idx, p_len);
    }
};

// TODO: 2D DP