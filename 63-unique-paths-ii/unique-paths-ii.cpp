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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n,obstacleGrid, dp);
    }
};