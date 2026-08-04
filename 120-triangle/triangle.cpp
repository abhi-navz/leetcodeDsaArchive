class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {

        int m = triangle.size();
        int n = triangle[m-1].size(); // last row size, even tho it's size would be n
 
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

        dp[0][0] = triangle[0][0];
        for(int i =1; i<m;i++){
            for(int j =0; j< triangle[i].size(); j++){
                int up = dp[i-1][j], diag = INT_MAX;
                if(j-1>= 0){
                    diag = dp[i-1][j-1];
                }
                dp[i][j] = triangle[i][j] + min (up, diag);
            }
        }
        
        int ans = INT_MAX;
        for(int x : dp[m-1]){
            ans = min (x, ans);
        }
        return ans;
    }
};