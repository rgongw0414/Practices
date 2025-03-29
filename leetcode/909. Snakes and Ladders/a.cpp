class Solution {
private:
    pair<int, int> intToPos(int square, int n) {
        int row = (square - 1) / n;
        int col = (square - 1) % n;
        if (row % 2 == 1) col = n - 1 - col;
        row = n - 1 - row;
        return {row, col};
    }

public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // TC: O(n^2)
        // SC: O(n^2)
        // BFS
        int n = board.size();
        queue<int> q; // map the square label to the number of move it takes
        unordered_set<int> visited;
        q.push(1);
        int moves = 0;
        while (!q.empty()) {
            int level_size = q.size();
            while (level_size--) {
                int curr = q.front();
                q.pop();
                for (int i = 1; i <= 6; i++) {
                    int next = curr + i;
                    auto [row, col] = intToPos(next, n);
                    if (board[row][col] != -1) next = board[row][col];
                    if (visited.count(next)) continue;
                    if (next == n * n) return moves + 1;
                    q.push(next);
                    visited.insert(next);
                }
            }
            moves++;
        }
        return -1;
    }
};