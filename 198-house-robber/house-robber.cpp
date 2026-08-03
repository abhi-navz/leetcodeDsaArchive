class Solution {
public:
    int solve(int idx, vector<int>&nums, vector<int>&dp){
        int n = nums.size();
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        // robbing 
        int r1 = nums[idx]+solve(idx+2, nums,dp);
        // not robbing
        int r2 = solve(idx+1,nums,dp);

        return dp[idx] =  max(r1,r2);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0, nums,dp);
    }
};