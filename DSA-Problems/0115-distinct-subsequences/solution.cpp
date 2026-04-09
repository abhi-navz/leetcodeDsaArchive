class Solution {
public:
    
    int numDistinct(string s, string t) {

       int m = s.size();
       int n = t.size();
        // taking size (m+1 * n+1) to not deal with negative indices by right shifting by 1.
        vector<vector<unsigned long long>>dp(m+1, vector< unsigned long long>(n+1,0));
        // dp[i][j] : represents ways to make t(0->j-1) using s[0->i-1];

        // base case when target is empty, we have one way to make it by deleting all chars of source
        for(int i = 0; i<=m; i++){
            dp[i][0] = 1;
        }

        // when source itself is empty,but the target is not(j>0) there's no way to make target
        for(int j =1; j<=n; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){

                // matching
                if(s[i-1] == t[j-1]){
                    // two options
                   unsigned long long take = dp[i-1][j-1];
                   unsigned long long notTake = dp[i-1][j];

                   dp[i][j] = take+notTake;

                }
                // not matching
                else{
                    // not take only
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[m][n];

        
    }
};
