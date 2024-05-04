class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // Better SC, but worse TC
        // Idea: Place each queen row by row, for first row: n choices, second second row: n-1 choices, etc.
        // Hence Time Complexity: O(N * N!), how to calculate this? For first row, we have n choices, for second row, we have n-1 choices, etc.
        // SC: O(N^2 + N) = O(N^2), where N for recursion function calls stack.
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        rowByRow(n, ans, board, 0);
        return ans;
    }

    bool isValid(vector<string>& board, int row, int col) {
        // TC: O(N)
        for (int i = 0; i <= row; i++) {
            // check each column of this row
            // now only the rows before row are placed, so we just have to take care of them, i.e. i = row; i--;
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            // negative diagonal direction
            // now only the rows before row are placed, so we just have to take care of them, i.e. i = row; i--;
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            // positive diagonal direction
            // now only the rows before row are placed, so we just have to take care of them, i.e. i = row; i--;
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void rowByRow(int& n, vector<vector<string>>& ans, vector<string>& board, int row) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                rowByRow(n, ans, board, row + 1);
                board[row][col] = '.';
            }
        }
    }
};

class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

public:
    vector<vector<string>> solveNQueens(int n) {
        // Idea: Place each queen row by row, for first row: n choices, second second row: n-1 choices, etc.
        // Hence TC: O(N!), how to calculate this? For first row, we have n choices, for second row, we have n-1 choices, etc.
        // SC: O(N^2 + 4N) = O(N^2), where 4N for recursion function calls stack and 3 hashsets.
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        rowByRow(n, ans, board, 0);
        return ans;
    }

    void rowByRow(int& n, vector<vector<string>>& ans, vector<string>& board, int row) {
        if (row >= n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (cols.find(col) != cols.end() || 
                    posDiag.find(row + col) != posDiag.end() || 
                    negDiag.find(row - col) != negDiag.end()) {
                continue;
            }
            board[row][col] = 'Q';
            cols.insert(col);
            posDiag.insert(row + col);
            negDiag.insert(row - col);
            rowByRow(n, ans, board, row + 1);
            board[row][col] = '.';
            cols.erase(col);
            posDiag.erase(row + col);
            negDiag.erase(row - col);
        }
    }
};