class Solution {
public:
    int uniquePaths(int m, int n) {
        // Calculate non-repeated #Permutation: Overflow
        if (m == 1 || n == 1) return 1;
        m--;
        n--;
        return (fact(m+n) / fact(m)) / fact(n);
    }

    unsigned long long fact(long long n) {
        unsigned long long tmp = 1;
        while (n > 1) {
            tmp *= n;
            n--;
        }
        return tmp;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Optimized #Permutation Calculation (Permutations of → and ↓)
        // (m+n)! / (m! * n!) = (m+n)(m+n-1)...(m+1) / n!
        // TC: O(n) 
        // SC: O(1)
        if (m == 1 || n == 1) return 1;
        m--;
        n--;
        if (m < n) swap(m, n);
        long long res = 1;
        int j = 1;
        for (int i = m + 1; i <= m + n; i++) {
            res *= i;
            res /= j;
            j++;
        }
        return res;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 2-D DP Bottom-Up
        // TC: O(m*n)
        // SC: O(m*n)
        if (m == 1 || n == 1) return 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1 ; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 1-D DP Bottom-Up 
        // TC: O(m*n)
        // SC: O(n)
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1 ; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i > 1 && j == 1) continue;
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n];
    }
};