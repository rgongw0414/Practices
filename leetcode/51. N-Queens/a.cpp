class Solution {
private:
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

public:
    vector<vector<string>> solveNQueens(int n) {
        // Idea: Place each queen row by row, for first row: n choices, second second row: n-1 choices, etc.
        // Hence TC: O(N!) *** Can be optimized to O(N^2) by using hashset to check if a queen can be placed at a cell. ***
        // SC: O(N^2 + N) = O(N^2), where N for recursion function calls stack.  *** Can be optimized to O(N) by using hashset to check if a queen can be placed at a cell. ***
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