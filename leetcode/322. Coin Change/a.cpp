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
        // TC: O(coins.length^amount) = O(N^t)
        // SC: O(t) = O(amount)
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