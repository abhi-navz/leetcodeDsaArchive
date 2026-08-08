class Solution {

public:
    int solve(int st,int amount, vector<int>&coins, vector<vector<int>>&dp){
        int n = coins.size();
        if(amount == 0) return 1;  

        if(dp[st][amount] != -1) return dp[st][amount];
        int ans =0;

        for(int i =st; i<n; i++){
            if(amount - coins[i] >= 0){
                ans += solve(i, amount-coins[i], coins,dp);
            }
        }

        return dp[st][amount] = ans;

    }
    int change(int amount, vector<int>& coins) {
       int n = coins.size();
       vector<vector<int>>dp(n, vector<int>(amount+1, -1));
       return solve(0,amount, coins,dp);
    }
};