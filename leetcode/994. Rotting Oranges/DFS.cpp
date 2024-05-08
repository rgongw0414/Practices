class Solution {
private:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Recursive DFS, less readable than BFS
        // In each cell, record the min time needed to rotten this orange (aka the shortest path from a rotten orange to a fresh orange),
        // so the max time is the required time to rotten all oranges.
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) DFS(grid, i, j, 2); // start from rotten oranges, so time start from 2
            }
        }

        int timeNeeded = 2;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) return -1; // there exists fresh oranges can't be reached
                timeNeeded = max(timeNeeded, grid[i][j]);
            }
        }
        return timeNeeded - 2;
    }

    void DFS(vector<vector<int>>& grid, int i , int j, int minute) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == 0) return; // empty cell
        if (grid[i][j] >= 2 && grid[i][j] < minute) return;
        grid[i][j] = minute; // grid[i][j] >= minute, indicating this is the minimal required time to rotten this orange so far, so we have to update it.
        for (auto &direction: directions) {
            int iStepped = i + direction.first;
            int jStepped = j + direction.second;
            DFS(grid, iStepped, jStepped, minute + 1);
        }
    }
};