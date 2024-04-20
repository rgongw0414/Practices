#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // cleaner code
        if (strs.size()==0) return {{""}};
        if (strs.size()==1) return {{strs[0]}};        
        unordered_map<string, vector<string>> table;
        for (auto & str: strs) {
            // O(strNum*(strLen*log(strLen)))
            auto tmp = str;
            // srtLen is constant, so O(strNum*strLen) = O(strNum*1) = O(strNum)
            sort(str.begin(), str.end());
            table[str].emplace_back(tmp);
        }

        vector<vector<string>> ans;
        for (auto const& elem: table) {
            ans.emplace_back(elem.second);
        }
        return ans;
        
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size()==0) return {{""}};
        if (strs.size()==1) return {{strs[0]}};        
        unordered_map<string, vector<string>> table;
        for (auto &str: strs) {
            vector<int> charVec(26, 0);
            string origStr = str;
            for (auto &c: str) {
                charVec[c-'a']++;
            }

            // read the chars from 'a' to 'z', store them as a sorted string
            string sortedStr = "";
            for (int i = 0; i < 26; i++) {
                int cnt = charVec[i];
                while (cnt--) sortedStr += (char)('a' + i);
            }
            table[sortedStr].push_back(origStr);
        }

        vector<vector<string>> ans;
        for (auto const& elem: table) {
            ans.emplace_back(elem.second);
        }
        return ans;
        
    }
};