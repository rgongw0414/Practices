class Solution {
public:
    int characterReplacement(string s, int k) {
        // O(2N)
        // worst case: ABABAB, given k is 0, i and j would iter through the array, so it is O(2N).
        // k: available times of modifying the minor char
        // e.g. in interval [AABA], major: A, minor: B
        int major = 0; // the count of major char in current interval [i, j]
        int i = 0, j = 0, ans = 0;
        vector<int> count(26, 0); // count of char in current interval [i, j]
        while (j < s.size()) {
            count[s[j]-'A']++;
            major = max(major, count[s[j]-'A']);
            if (j-i+1 - major > k) {
                // j-i+1: interval len
                // k is not enough to modify the minor chars,
                // which means current interval is not modifiable, so we have to move i, 
                // to update the interval
                count[s[i]-'A']--;
                i++; 
            }
            // since the interval is legal, which's modified by the code above (ln 12-19), 
            // so we can just compare ans (max len) with current interval len.
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};