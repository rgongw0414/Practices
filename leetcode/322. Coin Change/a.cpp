/*
coins = [1,2,5], amount = 11
Height: amount (t)
#Node: N^t, N = coins.length
       11
    1/ 2| 5\
   10   9   6
   /|\ /|\ /|\
   ... ... ...
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Bottom-up DP
        // TC: O(coins.length*amount) = O(N*t)
        // SC: O(amount) = O(t)
        vector<int> dp(amount+1, 10000+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (const int& coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return (dp[amount] == 10001) ? -1 : dp[amount];
    }
};

class Solution {
public:
    unordered_map<int, int> memo;
    int coinChange(vector<int>& coins, int amount) {
        // Recursion + Memoization
        // TC: O(coins.length*amount) = O(N*t)
        // SC: O(amount) = O(t)
        int coin_num = dfs(coins, amount);
        return (coin_num == 10001) ? -1 : coin_num;
    }

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0; // it takes 0 coin to change 0 dollar
        if (memo.count(amount)) return memo[amount];
        int min_coin_num = 10001;
        for (const int& coin : coins) {
            if (amount - coin >= 0) { // legit to use this coin 
                int cur_coin_num = dfs(coins, amount - coin) + 1;
                min_coin_num = min(min_coin_num, cur_coin_num);
            }
            memo[amount] = min_coin_num;
        }
        return min_coin_num;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // TC: O(coins.length^amount) = O(N^t)
        // SC: O(amount) = O(t)
        int coin_num = dfs(coins, amount);
        return (coin_num == 10001) ? -1 : coin_num;
    }

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0; // it takes 0 coin to change 0 dollar
        int min_coin_num = 10001;
        for (const int& coin : coins) {
            if (amount - coin >= 0) { // legit to use this coin 
                int cur_coin_num = dfs(coins, amount - coin) + 1;
                min_coin_num = min(min_coin_num, cur_coin_num);
            }
        }
        return min_coin_num;
    }
};