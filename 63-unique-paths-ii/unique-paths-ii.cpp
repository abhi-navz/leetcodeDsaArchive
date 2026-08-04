class Solution {
public:
    int solve(int row, int col, int m, int n, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        // base cae
        if (row == m - 1 && col == n - 1)
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];

        int right = 0, down = 0;
        if (row + 1 < m && col < n && mat[row][col] != 1)
            down = solve(row + 1, col, m, n, mat, dp);
        if (row < m && col + 1 < n && mat[row][col] != 1)
            right = solve(row, col + 1, m, n, mat, dp);

        return dp[row][col] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int col =0; col<n; col++){
            if(obstacleGrid[0][col] == 1) break;
            dp[0][col] = 1;
        }

        for(int row = 1; row<m; row++){
            if(obstacleGrid[row][0] == 1) break;
            dp[row][0] = 1;
        }

        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
        
    }
};