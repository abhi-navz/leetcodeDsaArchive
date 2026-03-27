class Solution {
public:
    int n;

    int helper(vector<int>&nums,int st, int idx, vector<int>&dp){
        // base case;
        if(idx < st) return 0;
        if(idx == st) return nums[st];

        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + helper(nums, st,idx-2,dp);
        int skip = helper(nums,st, idx-1,dp);

        return dp[idx] = max(take, skip); 
    }
    int rob(vector<int>& nums) {

        // we'll have to take two cases here 
        // case 1:  form 0 to n-2 
        // case 2: from 1 to n-1;
        n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int>dp(n, -1);
        int case1 = helper(nums,0,n-2,dp);

        fill(dp.begin(), dp.end(), -1);   // reset memo
        int case2  = helper(nums,1,n-1,dp);

        return max(case1,case2);
        
    }
};
