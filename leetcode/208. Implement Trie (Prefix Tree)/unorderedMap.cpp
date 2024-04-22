#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    // Using unordered_map is slower than vector
    unordered_map<char, Node*> children; // hash table from 'a' to 'z'
    bool endOfWord;
    Node() : endOfWord(false) {}
};


class Trie {
public:
    Node* root;
    Trie() {
        root = new Node(); // NOTE: isTail default set to true
    }
    
    void insert(string word) {
        Node* current = this->root; // current node
        for (char ch: word) {
            if (current->children.count(ch) == 0) {
                // ch is not in current node's children
                current->children[ch] = new Node();
            }
            current = current->children[ch];
        }
        current->endOfWord = true;
    }
    
    bool search(string word) {
        auto curr = root;
        bool found = true;
        for (int i = 0; i < (int)word.size(); i++) {
            char ch = word[i];
            if (curr->children.find(ch) == curr->children.end()) {
                found = false;
                break;
            }
            curr = curr->children[ch]; // root -> a -> p -> p -> l -> e
            // cout << i << ": " << ch << ", endOFWord: " << curr->endOfWord << "\n";
        }
        return found && curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        auto curr = root;
        bool found = true;
        for (char &ch: prefix) {
            if (curr->children.find(ch) == curr->children.end()) {
                found = false;
                break;
            }
            curr = curr->children[ch];
        }
        return found;
    }
};

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;   // returns true
    // cout << trie->search("app") << endl;     // returns false
    // cout << trie->startsWith("app") << endl; // returns true
    // trie->insert("app");   
    // cout << trie->search("app") << endl;     // returns true
    return 0;
}