class Solution {
private:
    struct Node {
        vector<Node*> children;
        bool endOfWord;
        Node() : children(26*2, nullptr), endOfWord(false) {}
    };
    Node* root;

public:
    bool exist(vector<vector<char>>& board, string word) {
        root = new Node();
        auto curr = root;
        for (auto &ch: word) {
            if ('a' <= ch and ch <= 'z') {
                if (!curr->children[ch - 'a']) {
                    curr->children[ch - 'a'] = new Node();
                }
                curr = curr->children[ch - 'a'];
            }
            else {
                if (!curr->children[26 + ch - 'A']) {
                    curr->children[26 + ch - 'A'] = new Node();
                }
                curr = curr->children[26 + ch - 'A'];
            }
        }
        // if endOfWord can be reached while traversing board, it means word can be constructed with the chars on the board.
        curr->endOfWord = true; 

        int boardH = (int)board.size();  // size_t is unsigned long under the hood, if board.size() > INT_MAX, it will cause overflow
        int boardW = (int)board[0].size();
        bool found = false;
        for (int i = 0; i < boardH; i++) {
            for (int j = 0; j < boardW; j++) {
                traverseFrom(i, j, board, found, root); // start traversing from (i, j)
            }
        }
        return found;
    }

    void traverseFrom(int i, int j, vector<vector<char>> &board, bool &found, Node* currNode) {
        if (board[i][j] == '#') return;
        int chIdx;
        if ('a' <= board[i][j] and board[i][j] <= 'z') {
            chIdx = board[i][j] - 'a';
        }
        else {
            chIdx = 26 + (board[i][j] - 'A');
        }
        currNode = currNode->children[chIdx];
        if (!currNode) return;
        if (currNode->endOfWord) {
            found = true; 
            return; // once endOfWord reached, it means the word has been constructed with the chars on board successfully.
        }
        int boardH = (int)board.size();  // size_t is unsigned long under the hood, if board.size() > INT_MAX, it will cause overflow
        int boardW = (int)board[0].size();
        char chAtThisPos = board[i][j];
        board[i][j] = '#'; // label this char as used
        if (i + 1 < boardH) traverseFrom(i + 1, j, board, found, currNode);
        if (i - 1 >= 0)     traverseFrom(i - 1, j, board, found, currNode);
        if (j + 1 < boardW) traverseFrom(i, j + 1, board, found, currNode);
        if (j - 1 >= 0)     traverseFrom(i, j - 1, board, found, currNode);
        board[i][j] = chAtThisPos;
    }
};