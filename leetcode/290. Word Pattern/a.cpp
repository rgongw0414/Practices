class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Bijection: One-to-one && onto (surjection)
        // - Similar problem: 205. Isomorphic Strings
        // TC: O(n), SC: O(n)
        std::istringstream iss(s);
        std::string word;
        std::vector<std::string> words;
        unordered_map<char, string> mapPS;
        unordered_map<string, char> mapSP;
        while (std::getline(iss, word, ' ')) {
            words.push_back(word); // Store each word in the vector by delimiting with space
        }
        if (pattern.size() != words.size()) return false; // bijection must have the same size in both domain and codomain
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];
            if ((mapPS.count(ch) && mapPS[ch] != word) ||
                (mapSP.count(word) && mapSP[word] != ch)) {
                return false;
            }
            mapPS[ch] = word;
            mapSP[word] = ch;
        }
        return true;
    }
};