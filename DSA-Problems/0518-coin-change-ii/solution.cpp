class Solution {
public:
    int n;

    int helper(int idx, int remAmt, vector<int>&coins, vector<vector<int>>&dp){

        // base case
        if(remAmt == 0) return 1;

        if(idx == n) return 0;

        if(dp[idx][remAmt] != -1) return dp[idx][remAmt];

        int notTake = helper(idx+1, remAmt, coins,dp);
        int take = 0;
        if(remAmt-coins[idx] >= 0){
            take = helper(idx, remAmt-coins[idx], coins,dp);
        }

        return dp[idx][remAmt] = take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(0,amount,coins,dp);
    }
};
