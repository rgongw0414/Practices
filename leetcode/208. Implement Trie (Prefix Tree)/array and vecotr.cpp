// class Node {
// public:
//     vector<Node*> children; // hash table from 'a' to 'z'
//     bool endOfWord;
//     Node() : children(26, nullptr), endOfWord(false) {}
// };

class Trie {
private:
    struct Node {
        // Node* children[26] = {}; // Initializing while constructing Node
        // bool endOfWord = false;
        Node* children[26]; // hash table from 'a' to 'z'
        bool endOfWord;
        Node() : endOfWord(false) {
                for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
        /*
        * 1. Initializing while constructing Node
        * Member variables are initialized directly in the constructor's member initializer list.
        * Happens before the constructor body is executed.
        * Potentially better performance, especially for non-trivial types or classes.
        *    Node() : endOfWord(false) {}, or 
        *    Node* children[26] = {}; // hash table from 'a' to 'z', initialized to nullptr
        *    bool endOfWord = false;
        2. Assignment after Node has benn constructed
        *    Node() { endOfWord = false; }
        */
    };
    Node* root;

public:
    Trie() {
        root = new Node(); // NOTE: isTail default set to true
    }
    
    void insert(string word) {
        Node* curr = this->root; // current node
        for (char &ch: word) {
            if (curr->children[ch - 'a'] == nullptr) {
                // ch is not in current node's children
                curr->children[ch - 'a'] = new Node();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        auto curr = root;
        bool found = true;
        for (int i = 0; i < (int)word.size(); i++) {
            char ch = word[i];
            if (curr->children[ch - 'a'] == nullptr) {
                found = false;
                break;
            }
            curr = curr->children[ch - 'a'];
        }
        return found && curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        bool found = true;
        for (char &ch: prefix) {
            if (curr->children[ch - 'a'] == nullptr) {
                found = false;
                break;
            }
            curr = curr->children[ch - 'a'];
        }
        return found;
    }
};



// vector instead of array
class Trie {
private:
    struct Node {
        vector<Node*> children; // hash table from 'a' to 'z'
        bool endOfWord;
        Node() : children(26, nullptr), endOfWord(false) {}
    };
    Node* root;
    
public:
    Trie() {
        root = new Node(); // NOTE: isTail default set to true
    }
    
    void insert(string word) {
        Node* curr = this->root; // current node
        for (char &ch: word) {
            if (curr->children[ch - 'a'] == nullptr) {
                // ch is not in current node's children
                curr->children[ch - 'a'] = new Node();
            }
            curr = curr->children[ch - 'a'];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        auto curr = root;
        bool found = true;
        for (int i = 0; i < (int)word.size(); i++) {
            char ch = word[i];
            if (curr->children[ch - 'a'] == nullptr) {
                found = false;
                break;
            }
            curr = curr->children[ch - 'a'];
        }
        return found && curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        bool found = true;
        for (char &ch: prefix) {
            if (curr->children[ch - 'a'] == nullptr) {
                found = false;
                break;
            }
            curr = curr->children[ch - 'a'];
        }
        return found;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */