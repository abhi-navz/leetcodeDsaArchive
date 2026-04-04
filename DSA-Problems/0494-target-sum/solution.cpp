class Solution {
public:
    int n,sum;

    int helper(int idx, int rem, vector<int>&arr,vector<vector<int>>&dp){

        if(rem < -sum || rem > sum) return 0;
        
        if(idx == n){
            if(rem == 0) return 1;
            else return 0;
        }
        

        if(dp[idx][rem+sum] != -1) return dp[idx][rem+sum];

        int plus = helper(idx+1, rem -arr[idx], arr,dp);
        
        int minus = helper(idx+1, rem+arr[idx], arr,dp);

       
        return dp[idx][rem+sum] = (plus+minus);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        sum = 0;
        for(int x: nums){
            sum += x;
        }

        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));

        return helper(0,target, nums,dp);

        
    }
};
