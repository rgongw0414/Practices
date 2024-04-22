class Node {
public:
    unordered_map<char, Node*> children; // hash table from 'a' to 'z'
    bool endOfWord;
    Node() {
        this->endOfWord = false;
    }
};

class Trie {
    Node* root; // better be private, and access with member functions
public:
    Trie() {
        this->root = new Node();
    }

    bool insertStr(string& str) {
        // return True if it can stop early
        if (this->root->children.size() > 1) return true; // common prefix does not exist, return ""
        Node* current = this->root; // current node
        for (auto ch: str) {
            if (current->children.count(ch) == 0) {
                // ch is not in current node's children
                current->children[ch] = new Node();
            }
            current = current->children[ch];
        }
        current->endOfWord = true;
        return false;
    }

    string lcp() {
        // return the least common prefix
        string ans;
        if (this->root->children.size() > 1) return ""; // if there are more than 1 branches, common prefix does not exist.
        
        auto current = this->root;        
        while(current->children.size() == 1 && !current->endOfWord) {            
            auto ch = current->children.begin()->first; // unordermap<char, *Node>; current->children.begin() is the only of child of current
            auto next = current->children.begin()->second;
            current = next;
            ans += ch;
        }
        return ans;
    }
};



// method 2: compare each string with the first string
class Solution {    
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto& str : strs) {            
            if (trie.insertStr(str)) {
                return "";
                break;
            }
        }
        return trie.lcp();
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size(); // current best prefix len
        for (int i = 1; i < strs.size(); i++) {
            int j = 0; // idx for each string pair's char comparison
            while (strs[0][j] == strs[i][j] && j < min(len, (int)strs[i].size())) {                
                j++;
            }
            len = j;
        }
        return strs[0].substr(0, len);
    }
};