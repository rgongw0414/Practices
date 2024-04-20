class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> windowMap, tMap; // char -> char count in the string
        // windowMap: the char count in current window
        for (auto ch: t) {
            tMap[ch]++;
        }
        int sLen = s.size(); // 1 <= sLen, tLen 
        int requirement = tMap.size(); // the number of requirement the substring s' have to achieve,
        int requirementSatisfied = 0;
        // for t = "ABC", the requirements of substring of s: 
        // 1: windowMap['A'] == 1, 
        // 2: windowMap['B'] == 1,
        // 3: windowMap['C'] == 1
        int left = 0, right; // two ptrs of current window
        int ansLeft = -1, ansRight = -1, windowLenMin = INT_MAX;
        for (right = 0; right < sLen; right++) {
            // idea: Expand the right pointer until all the characters of t are covered.
            char charRight = s[right]; // char pointed by right ptr
            windowMap[charRight]++;
            if (tMap.find(charRight) != tMap.end() and windowMap[charRight] == tMap[charRight]) {
                requirementSatisfied++;
            }
            // current window has covered all target chars, now move left ptr to shrink the window, 
            // until the requirement not satisfied anymore.
            while (requirementSatisfied == requirement) {
                if (right - left + 1 < windowLenMin) {
                    // smaller window found
                    ansLeft = left;
                    ansRight = right;
                    windowLenMin = ansRight - ansLeft + 1;
                }
                char charLeft = s[left]; // char pointed by right ptr
                windowMap[charLeft]--;
                if (tMap.find(charLeft) != tMap.end() and windowMap[charLeft] < tMap[charLeft]) {
                    requirementSatisfied--;
                }
                left++;
            }
        }
        if (windowLenMin == INT_MAX) return "";
        return s.substr(ansLeft, windowLenMin);
    }
};