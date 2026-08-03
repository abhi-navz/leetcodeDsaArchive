class Solution {
public:
    bool helper(int idx, int k, vector<int>& stones, vector<vector<int>>&dp) {
        int n = stones.size();
        if (idx == n-1)
            return true;

        if(dp[idx][k] != -1){
            return dp[idx][k]; // {0,1} false or true
        }    

        int i = idx + 1;

        for (int j = -1; j <= 1; j++) {
            int jump = k + j;
             

            while (i < n) {
                if (stones[idx] + jump < stones[i])
                    break;
                else if (stones[idx] + jump == stones[i]) {
                    if (helper(i, jump, stones,dp))
                        return dp[i][jump] =  true;
                }
                i++;   
            }
        }

        return dp[idx][k] =  false;
    }

    bool canCross(vector<int>& stones) {

        if(stones[1] != 1) return false;

        vector<vector<int>>dp(2001,vector<int>(2001,-1));
        return helper(1,1,stones,dp);
    }
};