class Solution {

    int solve(int row, int col, int m, int n, vector<vector<int>>&dp){
        // base cae 
        if(row == m-1 && col == n-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];

        int right =0, down =0;
        if(row+1 < m && col < n)
            down = solve(row+1,col, m, n,dp);
        if(row < m && col +1 < n)
            right = solve(row, col+1, m,n,dp);

        return dp[row][col] = right +down;    
    }
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(0,0,m,n,dp);
    }
};