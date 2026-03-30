class Solution {
public:
    int n;
    int INF = 1e9;
    int helper(vector<vector<int>>&mat,int row, int col,vector<vector<int>>&dp){

        // base cases
        if(col < 0 || col>n-1) return INT_MAX;
        if(row == n-1) return mat[row][col];

        if(dp[row][col] != INF) return dp[row][col];

        int mini = INF;

        for(int nextCol =0; nextCol<n; nextCol++){
           if(nextCol != col){
                mini  = min(mini,helper(mat,row+1,nextCol,dp));
           }
          
        }

        return dp[row][col] = mini+mat[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INF));
        
        int ans = INF;
        for(int col=0; col<n; col++){
            ans = min(ans,helper(matrix,0,col,dp));
        }
        
        return ans;
    }
};    
