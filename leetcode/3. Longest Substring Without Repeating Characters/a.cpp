class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Time: O(N)
        if (s.size() <= 1)
            return s.size();

        // idx record of seen chars; 128: len of ascii char
        // default -1: haven't seen before
        vector<int> seen(128, -1); 
        int cur_start = 0; // the start idx of current sub-str
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i]] >= 0 and seen[s[i]] >= cur_start) {
                //  s        s'    i
                // [q, r, s, v, b, s, p, k, r]
                // s[i] is repeated, so i must move to the next char of the existing one
                cur_start = seen[s[i]] + 1;

                // explaination of 'seen[s[i]] >= cur_start': 
                // considering "vbspkr", we seen r in s[1],
                // and s[cur_start] now is v, so we must make sure 'seen[s[i]] >= cur_start' satisfied.
            } 
            ans = max(ans, i - cur_start + 1);
            seen[s[i]] = i; // update the latest idx of s[i]
        }
        return ans;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Time: O(2N)
        if (s.size() <= 1)
            return s.size();
        unordered_set<char> m;
        int i = 0, j = 1;
        m.insert(s[0]);
        int ans = 1, cnt = 1;
        while (j < s.size()) {
            if (!m.count(s[j])) {
                m.insert(s[j]);
                cnt++;
                ans = max(ans, cnt);
            } else {
                //  i        i'    j
                // [q, r, s, v, b, s, p, k]
                // s[j] is repeated, so i must move to the next char of the existing one
                while (s[i] != s[j]) {
                    m.erase(s[i]);
                    i++;
                }
                i++;
                cnt = m.size();
            }
            j++;
        }
        return ans;
    }
};