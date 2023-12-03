#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

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

    bool insertStr(string str) {
        // return True if it can stop early
        Node* current = this->root; // current node
        for (auto ch: str) {
            if (current->children.count(ch) == 0) {
                // ch is not in current node's children
                current->children[ch] = new Node();
            }
            current = current->children[ch];
            if (this->root->children.size() > 1) return true; // common prefix does not exist, return ""
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

string solve_14() {
    Trie trie;
    vector<string> strs = {"hello", "helee", "helff"};
    for (auto str: strs) {
        if (trie.insertStr(str)) {
            return "";
            break;
        }
    }
    auto ans = trie.lcp();
    cout << ans << endl;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    solve_14();
}