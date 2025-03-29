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
        int n = board.size();
        queue<pair<int, int>> q; // map the square label to the number of move it takes
        unordered_set<int> visited;
        q.push({1, 0});
        while (!q.empty()) {
            auto [curr, moves] = q.front();
            q.pop();
            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                auto [row, col] = intToPos(next, n);
                if (board[row][col] != -1) {
                    next = board[row][col];
                }

                /* Note that we don't need to check if mut_num + 1 is minimum
                * because we are using BFS, which guarantees that the first time we reach
                * the end square, it is the minimum number of moves needed. */
                if (next == n * n) {
                    return moves + 1;
                }
                if (visited.count(next)) continue;
                q.push({next, moves + 1});
                visited.insert(next);
            }
        }
        return -1;
    }
};