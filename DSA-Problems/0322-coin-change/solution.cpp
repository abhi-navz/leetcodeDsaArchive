class Solution {
public:
    int helper(vector<int>&coins, int amount, vector<int>&dp){
        // base case
        if(amount == 0) return 0;
        if(amount <0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for(int coin: coins){
            int res = helper(coins, amount - coin, dp);
            if(res != INT_MAX){
                ans = min(ans, res+1);
            }
            
        }
        return dp[amount] = ans;
       
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,-1);
        int ans = helper(coins,amount,dp);
        if(ans == INT_MAX) return -1;
        return ans;

        
    }
};
