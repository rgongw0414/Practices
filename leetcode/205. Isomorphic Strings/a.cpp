class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Two maps checking if the mapping from s to/from t is consistent
        // TC: O(n), SC: O(n)
        unordered_map<char, char> mapST, mapTS; // map from s to t, map from t to s
        for (int i = 0; i < s.length(); i++) { 
            // check if the mapping of both maps are consistent (mapping s[i] to t[i])
            if ((mapST.count(s[i]) && mapST[s[i]] != t[i]) || 
                (mapTS.count(t[i]) && mapTS[t[i]] != s[i])) { 
                return false; 
            }            
            mapST[s[i]] = t[i];
            mapTS[t[i]] = s[i];
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(256, -1); // Stores the index of each char's last occurence in string s
        vector<int> indexT(256, -1); 
        
        for (int i = 0; i < s.length(); i++) { 
            // Check if last occurence of the chars in s is different from the corresponding char in t
            if (indexS[s[i]] != indexT[t[i]]) { 
                return false; 
            }            
            indexS[s[i]] = i; // updating the last occurrence of the current character
            indexT[t[i]] = i;
        }
        return true;
    }
};