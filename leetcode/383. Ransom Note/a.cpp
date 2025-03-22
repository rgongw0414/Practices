class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // TC:O(n), SC:O(1)
        int r_bucket[26] = {0};
        int m_bucket[26] = {0};
        for (const char& ch: ransomNote) {
            r_bucket[ch - 'a']++;
        }
        for (const char& ch: magazine) {
            m_bucket[ch - 'a']++;
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (m_bucket[i] < r_bucket[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // TC:O(n), SC:O(1)
        unordered_map<char, int> ch_map;
        for (const char& ch: magazine) {
            ch_map[ch]++;
        }
        int cnt = 0;
        for (const char& ch: ransomNote) {
            if (ch_map[ch] > 0) {
                cnt++;
                ch_map[ch]--;
            }
            if (cnt == ransomNote.size()) return true;
        }
        return false;
    }
};