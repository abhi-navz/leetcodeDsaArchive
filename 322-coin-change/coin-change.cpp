class Solution {
    int INF = 1e7;
public:
    int solver(int amount, vector<int>&coins, vector<int>&dp){
        // base case 
        if(amount == 0) return 0;
        if(dp[amount] != -1){
            return dp[amount];
        }

        int ans = INF;
        for(int coin : coins){
            if(coin <= amount){
                int res = solver(amount-coin, coins, dp);
                if(res != INF){
                    ans = min (ans, 1+res);
                }
            }
        }
        return dp[amount] = ans;


    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);

        int numCoins = solver(amount, coins, dp);
        if(numCoins == INF) return -1;
        return numCoins;

    }
};