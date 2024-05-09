class Solution {
private:
    int boardHeight;
    int boardWidth;

public:
    void solve(vector<vector<char>>& board) {
        // DFS starts from edge cells
        // Idea: A region can not be captured is the one that can be reached from 'O' cells in edge, 
        //      so starts from edge cells, and mark each reachable cell 'E', we can know all regions can't be captured.
        boardHeight = board.size();
        boardWidth = board[0].size();

        // Starts from edge cells
        for (int i = 0; i < boardHeight; i++) {
            if (board[i][0] == 'O') DFS(board, i, 0);
            if (board[i][boardWidth - 1] == 'O') DFS(board, i, boardWidth - 1);
        }
        for (int j = 0; j < boardWidth; j++) {
            if (board[0][j] == 'O') DFS(board, 0, j);
            if (board[boardHeight - 1][j] == 'O') DFS(board, boardHeight - 1, j);
        }

        for (int i = 0; i < boardHeight; i++) {
            for (int j = 0; j < boardWidth; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'E') board[i][j] = 'O';
            }
        }
        return;
    }

    void DFS(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= boardHeight || j < 0 || j >= boardWidth || board[i][j] != 'O') {
            return;
        }
        board[i][j] = 'E';
        DFS(board, i + 1, j);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
        DFS(board, i, j - 1);
    }
};