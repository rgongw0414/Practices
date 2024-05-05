class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Backtracking (DFS), "bottom-up" DFS counting area
        // Time: O(m x n)
        // Space: O(m x n)
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int currArea = traverse(grid, i, j);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }

    int traverse(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 0;
        int areaUp    = traverse(grid, i + 1, j); // the area of starting from (i + 1, j)
        int areaDown  = traverse(grid, i - 1, j); // ...
        int areaRight = traverse(grid, i, j + 1); // ...
        int areaLeft  = traverse(grid, i, j - 1); // ...
        // grid[i][j] = '1'; we don't need this because we are traversing a island, once we stepped into a island, 
        // we would definitely traverse this island all the way, so we don't have to reset to '1' for revisiting.
        // Note that '1' is for revisiting, e.g. in word search II, each char can be reused by every strings.
        return 1 + areaUp + areaDown + areaRight + areaLeft;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // Backtracking (DFS), top-down increasing area, and decreasing area bottom-up
        // Time: O(m x n)
        // Space: O(m x n)
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int currArea = 1;
                    traverse(grid, i, j, maxArea, currArea);
                }
                
            }
        }
        return maxArea;
    }

    void traverse(vector<vector<int>>& grid, int i, int j, int& maxArea, int& currArea) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            currArea--;
            return;
        }
        grid[i][j] = 0;
        traverse(grid, i + 1, j, maxArea, ++currArea);
        traverse(grid, i - 1, j, maxArea, ++currArea);
        traverse(grid, i, j + 1, maxArea, ++currArea);
        traverse(grid, i, j - 1, maxArea, ++currArea);
        maxArea = max(maxArea, currArea);
        // grid[i][j] = '1'; we don't need this because we are traversing a island, once we stepped into a island, 
        // we would definitely traverse this island all the way, so we don't have to reset to '1' for revisiting.
        // Note that '1' is for revisiting, e.g. in word search II, each char can be reused by every strings.
    }
};