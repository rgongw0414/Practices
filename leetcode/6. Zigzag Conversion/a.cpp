#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // TC: O(n), SC: O(n)
        if (numRows == 1) return s;
        vector<string> matrix(numRows, ""); // to represent the zigzag matrix
        int row = 0;
        bool increasing = true; // from row_0 to row_numRows-1
        for (int i = 0; i < s.size(); i++) {
            matrix[row] += s[i];
            if (increasing) {
                row++;
            }
            else {
                row--;
            }
            if (row == numRows) {
                row = numRows - 2;
                increasing = false;
            }
            if (row == 0) {
                increasing = true;
            }
        }
        string ans = "";
        for (int i = 0; i < numRows; i++) {
            for (auto& ch: matrix[i]) {
                // cout << ch;
                if (ch == ' ') continue;
                ans += ch;
            }
            // cout << endl;
        }
        return ans;
    }
};

int main() {
    int numRows = 4;
    string s = "PAYPALISHIRING";
    Solution solution;
    cout << solution.convert(s, numRows) << endl;

    return 0;
}