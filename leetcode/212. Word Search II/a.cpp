#include <bits/stdc++.h>
using namespace std;

/// TC: beats 25.23%, SC: beats 27.11%
class Solution {
private:
    struct Node {
        vector<Node*> children;
        bool endOfWord;
        Node () : children(26, nullptr), endOfWord(false) {}
    };
    Node* root;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // trie, optimized version, build trie with words, so that we only search each word in words one time.
        // build the trie with the words we are looking for
        root = new Node(); // root of trie
        // insert all words into trie
        // *** idea: if one of the endOfWord is reached during traversing board, it indicates that the word can be found on the board. ***
        for (auto &word: words) {
            Node* currNode = root;
            for (auto &ch: word) {
                if (!currNode->children[ch - 'a']) {
                    currNode->children[ch - 'a'] = new Node();
                }
                currNode = currNode->children[ch - 'a'];
            }
            currNode->endOfWord = true; 
        }

        vector<string> ans;
        size_t boardH = board.size(), boardW = board[0].size();
        for (size_t i = 0; i < boardH; i++) {
            for (size_t j = 0; j < boardW; j++) {
                // build trie by traversing starting from all positions on the board
                traverseBoardFrom(i, j, board, root, ans, ""); // from (i, j), traverse all 
            }
        }
        return ans;
    }

    void traverseBoardFrom(size_t i, size_t j, vector<vector<char>> &board, Node* currNode, vector<string> &ans, string currWord) {
        // O(boardH * boardW), worst case: traverse all the board cells
        // (i, j): current char position
        // currWord: current word formed by the chars on the board while traversing
        if (board[i][j] == '#') return;
        size_t chIdx = board[i][j] - 'a';
        currNode = currNode->children[chIdx];
        if (!currNode) return; // *** where early stopping happens ***
        currWord += board[i][j]; // append new char
        if (currNode->endOfWord) {
            ans.push_back(currWord);
            currNode->endOfWord = false; // avoid duplicate, e.g. words = [["a", "aa", "aaa"]]
        }
        char ch = board[i][j];
        board[i][j] = '#';
        // (int)board.size(): boardHeight, (int)board[0].size(): boardWidth
        if ((int)i + 1 < board.size())    traverseBoardFrom(i + 1, j, board, currNode, ans, currWord); // traverse all possible paths (DFS)
        if ((int)i - 1 >= 0)                   traverseBoardFrom(i - 1, j, board, currNode, ans, currWord);
        if ((int)j + 1 < board[0].size()) traverseBoardFrom(i, j + 1, board, currNode, ans, currWord);
        if ((int)j - 1 >= 0)                   traverseBoardFrom(i, j - 1, board, currNode, ans, currWord);
        board[i][j] = ch;
    }
};

/// TLE
// class Solution {
// private:
//     struct Node {
//         vector<Node*> children;
//         Node () : children(26, nullptr) {}
//     };
//     Node* root;
// public:

//     vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//         // trie, TLE caused by building trie with all possible path from each cell on the board
//         root = new Node(); // root of trie
//         auto curr = root;
//         int boardH = board.size(), boardW = board[0].size();
//         for (int i = 0; i < boardH; i++) {
//             for (int j = 0; j < boardW; j++) {
//                 // build trie by traversing starting from all positions on the board
//                 traverseBoardFrom(i, j, boardH, boardW, board, root); // from (i, j), traverse all 
//             }
//         }
//         bool found = false;
//         vector<string> ans;
//         for (auto &word: words) {
//             found = search(word, root);
//             if (found) ans.push_back(word);
//         }
//         return ans;
//     }

//     void traverseBoardFrom(int i, int j, int &boardH, int &boardW, vector<vector<char>> &board, Node* curr) {
//         // O(boardH * boardW), worst case: traverse all the board cells
//         // (i, j): current char position
//         if (!curr || i < 0 || i >= boardH || j < 0 || j >= boardW || board[i][j] == '#') return;
//         int chIdx = board[i][j] - 'a';
//         if (!curr->children[chIdx]) {
//             curr->children[chIdx] = new Node();
//         }
//         curr = curr->children[chIdx];
//         char ch = board[i][j];
//         board[i][j] = '#';
//         traverseBoardFrom(i + 1, j, boardH, boardW, board, curr);
//         traverseBoardFrom(i - 1, j, boardH, boardW, board, curr);
//         traverseBoardFrom(i, j + 1, boardH, boardW, board, curr);
//         traverseBoardFrom(i, j - 1, boardH, boardW, board, curr);
//         board[i][j] = ch;
//     }

//     bool search(string &word, Node* curr) {
//         bool found = true;
//         for (auto &ch: word) {
//             if (!curr->children[ch - 'a']) {
//                 found = false;
//                 break;
//             }
//             curr = curr->children[ch - 'a'];
//         }
//         return found;
//     }
// };

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'}};
    cout << "board size: " << board.size() << " " << board[0].size() << endl;
    vector<string> words = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> ans = s.findWords(board, words);
    for (auto &str: ans) {
        cout << str << endl;
    }
    return 0;
}