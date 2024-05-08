class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS trick, push each rotten orange to queue first,
        // i.e. start traversing from each rotten orange "in turn" in every present time.
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> idxQ; // queue of coordinates
        int freshCnt = 0; // for dealing with edge cases
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) freshCnt++;
                else if (grid[i][j] == 2) idxQ.push({i, j});
            }
        }
        int time = 0;
        while (!idxQ.empty()) {
            int currNodeNum = idxQ.size();
            while (currNodeNum--) {
                int currX = idxQ.front().first;
                int currY = idxQ.front().second;
                idxQ.pop();

                for (auto &direction: directions) {
                    int xStepped = currX + direction.first;
                    int yStepped = currY + direction.second;
                    if (xStepped < 0 || xStepped >= grid.size() || yStepped < 0 || yStepped >= grid[0].size() || grid[xStepped][yStepped] != 1) {
                        continue;
                    }
                    freshCnt--;
                    grid[xStepped][yStepped] = 2;
                    idxQ.push({xStepped, yStepped});
                }
            }
            time++;
        }
        if (freshCnt > 0) return -1; // still got fresh oranges
        if (freshCnt == 0 and time == 0) return 0; // already no fresh oranges in the begining
        return time - 1;
    }
};