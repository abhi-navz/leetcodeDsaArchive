class Solution {
public:
    int m,n;
    // int helper(int i, int j, string &s1, string &s2 , vector<vector<int>>&dp){

    //     if(i== m || j == n) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s1[i] == s2[j]){
    //         return dp[i][j] = 1+ helper(i+1,j+1, s1,s2,dp);
    //     }else{
    //         return dp[i][j] = max(helper(i+1,j,s1,s2,dp), helper(i,j+1,s1,s2,dp));
    //     }
    // }

    int longestCommonSubsequence(string text1, string text2) {
        
        m = text1.size();
        n = text2.size();

        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        // base case : last row and last col should be zero.

        for(int i = m-1; i>=0; i--){
            for(int j= n-1; j>=0; j--){

                if(text1[i] == text2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    dp[i][j]  = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }


        return dp[0][0];
    }
};