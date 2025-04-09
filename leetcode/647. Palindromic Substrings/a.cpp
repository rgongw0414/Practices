// Same as LeetCode 5
class Solution {
public:
    int countSubstrings(string s) {
        // Two pointers
        // TC: O(n^2)
        // SC: O(1)
        // Idea: Take each char as the palindrome center, and expand to left and right
        int p_cnt = 0; // index of the palindrome starting pos
        for (int i = 0; i < s.size(); i++) { 
            int L = i, R = i; // odd-len panlindrom
            while (L >= 0 && R < s.size() && s[L] == s[R]) {
                p_cnt++;
                L--;
                R++;
            }

            L = i, R = i + 1; // even-len panlindrom
            while (L >= 0 && R < s.size() && s[L] == s[R]) {
                p_cnt++;
                L--;
                R++;
            }
        }
        return p_cnt;
    }
};