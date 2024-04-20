class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Sliding size-fixed window 
        // TC: O(N)
        // SC: O(1)
        if (s2.size() < s1.size())
            return false;
        vector<int> freqS1(26, 0);
        for (char c : s1)
            freqS1[c - 'a']++;

        vector<int> freqS2(26, 0);
        int i = 0, j = 0;

        while (j < s2.size()) {
            freqS2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size()) {
                // window size hit, check freq equls or not.
                if (freqS1 == freqS2)
                    return true;
            }

            // move window
            if (j - i + 1 < s1.size())
                j++;
            else {
                freqS2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // O(N^2), freq table, brute-force
        if (s2.size() < s1.size()) return false;
        vector<int> count1(26, 0); // count of char appearance
        for (auto const& ch: s1) {
            count1[ch-'a']++;
        }
        vector<int> tmp(26, 0); // count of char appearance
        tmp = count1;
        bool ans = false;
        for (int i = 0; i < s2.size()-s1.size()+1; i++) {
            if (count1[s2[i]-'a'] == 0) {
                // s2[i] is not in s1
                continue;
            }
            int cnt = 0;
            for (int j = 0; j < s1.size(); j++) {
                if (count1[s2[i+j]-'a'] == 0) {
                    // s2[i+j] is not in s1
                    break;
                }
                cnt++; // s2[i+j] is in s1
                count1[s2[i+j]-'a']--;
            }
            if (cnt == s1.size()) {
                ans = true;
                break;
            }
            count1 = tmp;
        }
        return ans;
    }
};