class Solution {
private:
vector<bool> col_occupied, pos_diag_occupied, neg_diag_occupied;

public:
    int totalNQueens(int n) {
        // Fastest way to check if a column or diagonal is occupied is to use a boolean array
        // TC = O(N!): we have N choices in the first row, N-1 in the second row, N-2 in the next and so on... which brings overall time complexity to O(N!)
        // SC = O(N): we are using 3 sets to keep track of the occupied columns and diagonals, also the depth of recursion is N
        col_occupied.resize(n, false);
        pos_diag_occupied.resize(2 * n, false);
        neg_diag_occupied.resize(2 * n, false);
        int sol_num = 0;
        DFS(0, sol_num, n);
        return sol_num;
    }

    void DFS(int row, int& sol_num, int& n) {
        if (row == n) {
            sol_num++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (col_occupied[col] || 
                pos_diag_occupied[row+col] || 
                neg_diag_occupied[row-col+n]) continue;
            col_occupied[col] = true;
            pos_diag_occupied[row+col] = true;
            neg_diag_occupied[row-col+n] = true;
            DFS(row + 1, sol_num, n);
            col_occupied[col] = false;
            pos_diag_occupied[row+col] = false;
            neg_diag_occupied[row-col+n] = false;
        }
    }
};

class Solution {
private:
unordered_set<int> col_occupied, pos_diag_occupied, neg_diag_occupied;

public:
    int totalNQueens(int n) {
        // TC = O(N!): we have N choices in the first row, N-1 in the second row, N-2 in the next and so on... which brings overall time complexity to O(N!)
        // SC = O(N): we are using 3 sets to keep track of the occupied columns and diagonals, also the depth of recursion is N
        int sol_num = 0;
        DFS(0, sol_num, n);
        return sol_num;
    }

    void DFS(int row, int& sol_num, int& n) {
        if (row == n) {
            sol_num++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (col_occupied.count(col) || 
                pos_diag_occupied.count(row+col) || 
                neg_diag_occupied.count(row-col)) continue;
            col_occupied.insert(col);
            pos_diag_occupied.insert(row+col);
            neg_diag_occupied.insert(row-col);
            DFS(row + 1, sol_num, n);
            col_occupied.erase(col);
            pos_diag_occupied.erase(row+col);
            neg_diag_occupied.erase(row-col);
        }
    }
};