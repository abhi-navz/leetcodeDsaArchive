class Solution {
public:
    int minInsertions(string s) {

        int n = s.size();

        // intuiton find length of lps
        // now the lps string will be palindromic itself, i just need to insert
        // a counterpart for all the remaining charcters. which will be equal to
        // to the no of characters remaining that is n - lps;

        // finding lps
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>>dp(n+1, vector<int>(n+1,0));

        for(int i = 1;i<=n; i++){
            for(int j = 1; j<=n; j++){

                if(s[i-1] == rev[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int lps = dp[n][n];

        return n - lps;

    }
};
