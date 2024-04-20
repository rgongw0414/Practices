class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> squares[3][3];
        for (int i = 0; i < 9; i++) {
            unordered_set<char> rSet;
            unordered_set<char> cSet;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                  if (rSet.count(board[i][j]) == 0) rSet.emplace(board[i][j]);
                  else return false;
                  int si = i / 3, sj = j / 3;
                  if (squares[si][sj].count(board[i][j]) == 0) squares[si][sj].emplace(board[i][j]);
                  else return false;
                }
                if (board[j][i] != '.') {
                  if (cSet.count(board[j][i]) == 0) cSet.emplace(board[j][i]);
                  else return false;
                }
            }
        }
        return true;
    }
};