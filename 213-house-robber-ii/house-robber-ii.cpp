class Solution {
public:

    int solve(vector<int>& nums, int st, int en){

        if(st == en) return nums[st];

        int n = nums.size();
        vector<int> dp(n);

        dp[st] = nums[st];
        dp[st+1] = max(nums[st], nums[st+1]);

        for(int i = st+2; i <= en; i++){
            int take = nums[i] + dp[i-2];
            int skip = dp[i-1];
            dp[i] = max(take, skip);
        }

        return dp[en];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];

        int case1 = solve(nums, 0, n-2);
        int case2 = solve(nums, 1, n-1);

        return max(case1, case2);
    }
};