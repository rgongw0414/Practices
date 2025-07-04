class Solution {
public:
    int lengthOfLastWord(string s) {
        // TC=O(N), SC=O(1)
        int ans = 0;
        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ') { 
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            i--;
            ans++;
        }
        return ans;
    }
};