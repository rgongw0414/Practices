/*
    Top & left pacific, bottom & right atlantic, determine spots that flow to both

    Instead of inside out, but from oceans to spots where rain could flow from
    Faster bc avoids repeated work: cells along a path can also reach that ocean

    Time: O(gridWidth x gridHeight)
    Space: O(gridWidth x gridHeight)
*/

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // DFS, need some tricks to solve
        gridWidth = heights.size();
        gridHeight = heights[0].size();
        vector<vector<bool>> pacific(gridWidth, vector<bool>(gridHeight));
        vector<vector<bool>> atlantic(gridWidth, vector<bool>(gridHeight));
        
        for (int i = 0; i < gridWidth; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, gridHeight - 1);
        }
        
        for (int j = 0; j < gridHeight; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, gridWidth - 1, j);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < gridWidth; i++) {
            for (int j = 0; j < gridHeight; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    int gridWidth;
    int gridHeight;
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        // !visited[i - 1][j]: Avoid revisiting same spot
        // heights[i - 1][j] >= heights[i][j]: 
        //     Because we are starting from the spots next to the ocean, 
        //     so all the spots that the rain can flow from, also, are the spots that can reach the ocean.
        if (i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j]) {
            dfs(heights, visited, i - 1, j);
        }
        if (i < gridWidth - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j]) {
            dfs(heights, visited, i + 1, j);
        }
        if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j]) {
            dfs(heights, visited, i, j - 1);
        }
        if (j < gridHeight - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j]) {
            dfs(heights, visited, i, j + 1);
        }
    }
};
