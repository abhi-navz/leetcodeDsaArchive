class Solution {
public:
    int n;
    
    bool helper(vector<int>&arr, int ind ,int target,vector<vector<int>>&dp){

        if(target == 0) return true;
        if(ind == n) return false;

        if(dp[ind][target] != -1) return dp[ind][target];

        bool take = false;

        if(target - arr[ind] >= 0){
           take =  helper(arr,ind+1,target-arr[ind],dp);
        }

        bool notTake = helper(arr,ind+1,target,dp);

        return dp[ind][target] = take||notTake;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        
        for(int x: nums){
            sum += x;
        }

        if(sum %2 != 0) return false;

        int target = sum/2;

        vector<vector<int>>dp(n,vector<int>(target+1, -1));
        
        return helper(nums,0,target,dp);
        
    }
};
