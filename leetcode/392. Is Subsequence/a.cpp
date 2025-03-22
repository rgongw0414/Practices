class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int i = 0; // idx of s
        int j = 0; // idx of t
        int cnt = 0; 
        while (j < t.size()) {
            if (s[i] == t[j]) {
                i++;
                cnt++;
            }
            if (cnt == (int)s.size()) return true;
            j++;
        }
        return false;
    }
};