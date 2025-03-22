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

/*
while (iss >> word) {
    words.push_back(word); // Extract each word and add it to the vector
}
  >> operator only treats whitespace (spaces, tabs, and newlines) as the default delimiter to extract words or tokens from a stream.
use getline() to extract words from a stream with a custom delimiter
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p2i; // Mapping of pattern to the index where it was last seen
        unordered_map<string, int> w2i;
        istringstream in(s);
        string word;
        int i = 0, n = pattern.size();
        
        for (word; in >> word; i++) {
            if (i == n || p2i[pattern[i]] != w2i[word]) return false; // If it reaches end before all the words in string 's' are traversed || if values of keys : pattern[i] & word don't match return false
            
            p2i[pattern[i]] = w2i[word] = i + 1; // Otherwise map to both to a value i + 1
        }
        return i == n; // both the lengths should be equal
    }
};