class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total =0;
        for(int x : nums){
            total += x;
        }

        if(total %2 == 1) return false;
        int target = total/2;

        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));

        // base case
        dp[n][0] = 1; // can i make 0 from row n that is with no elemtnts
        for(int t =1; t<=target; t++){
            dp[n][t] = 0; // obciously can't make anything greater than 0 with no elements
        }

        for(int i = n-1; i>=0; i--){
            for(int t =0; t<= target; t++){

                bool take = false;
                if((t - nums[i]) >=0){
                    take = dp[i+1][t-nums[i]];
                }
                bool notTake = dp[i+1][t];

                dp[i][t] = take || notTake;
            }
        }

        return dp[0][target];
    }
};