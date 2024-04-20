class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(log(m*n)) (binary search)
        bool found = false;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = m * n - 1;
        while (i <= j) {
            int mid = i + (j-i) / 2;
            int idx1 = mid / n, idx2 = mid % n;
            if (matrix[idx1][idx2] == target) {
                found = true;
                break;
            }
            else if (matrix[idx1][idx2] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return found;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(m*n) (brute-force)
        bool found = false;
        for (auto const& row: matrix) {
            for (auto const& elem: row) {
                if (elem == target) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        return found;
    }
};