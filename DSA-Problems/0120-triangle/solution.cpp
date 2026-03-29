class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        vector<vector<int>> dp(m);

        for(int i = 0; i < m; i++){
            dp[i].resize(triangle[i].size());
        }

        dp[0][0] = triangle[0][0];

        for(int row =1; row<m; row++){
            for(int col =0; col<= row; col++){
                
                int up = INT_MAX;
                int diag = INT_MAX;

                if(col < triangle[row-1].size()){
                    up = dp[row-1][col];
                }
                if(col>0){
                    diag = dp[row-1][col-1];
                }

                dp[row][col] = triangle[row][col] + min(up,diag);

                
            }
        }

        int ans = INT_MAX;

        for(int col = 0; col < triangle[m-1].size(); col++){
            ans = min(ans, dp[m-1][col]);
        }

        return ans;

        
    }
};
