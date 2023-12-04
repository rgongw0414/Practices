#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define eb emplace_back
#define ef emplace_front
#define endl '\n'
using namespace std;

class Node {
public:
    // smart pointer: unique_ptr<Node>, which automaticlly delete the pointer when it is out of scope.
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

/*
// write a binary search tree

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
    Node* root;
public:
    BST() {
        this->root = nullptr;
    }

    void insert(int val) {
        if (this->root == nullptr) {
            this->root = new Node(val);
            return;
        }
        auto current = this->root;
        while (true) {
            if (val < current->val) {
                if (current->left == nullptr) {
                    current->left = new Node(val);
                    break;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(val);
                    break;
                }
                current = current->right;
            }
        }
    }

    void inorder() {
        inorder(this->root);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void preorder() {
        preorder(this->root);
    }

    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder() {
        postorder(this->root);
    }

    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

    void bfs() {
        queue<Node*> q;
        q.push(this->root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
    }

    void dfs() {
        stack<Node*> s;
        s.push(this->root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            cout << node->val << " ";
            if (node->right != nullptr) s.push(node->right);
            if (node->left != nullptr) s.push(node->left);
        }
    }

    void dfs_recursive() {
        dfs_recursive(this->root);
    }

    void dfs_recursive(Node* node) {
        if (node == nullptr) return;
        cout << node
    }
};
*/