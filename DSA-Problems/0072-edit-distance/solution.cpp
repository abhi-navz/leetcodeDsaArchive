class Solution {
public:

    int minDistance(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        // state dp[i][j] represents min no of operations required to convwert s[0->i-1] to t[0->j-1]

        // base case 

        // 1. if t is empty, delete everything from s
        for(int i = 0; i<=m; i++){
            dp[i][0] = i;
        }

        // 3. if s is empty, add everthing from t
        for(int j =0; j<=n; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i<=m;i++){
            for(int j = 1; j<=n; j++){

                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{

                    int insert = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min(insert, min(del,replace));
                }
            }
        }

        return dp[m][n];
    }
};
