class Solution {
public:
    int n;
    int helper(vector<vector<int>>& grid, int r1, int c1, int r2,vector<vector<vector<int>>>&dp) {

        int c2 = r1 + c1 - r2; // r1+c1 = r2+c2;

        // check boundaries
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) {
            return -1e9;
        }

        // if cell is blocked
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        // base case reached at (n-1,n-1)
        // since r1+c1 = r2+c2; so if r1 = n-1 and c2 = n-1 => r2 = n-1 and c2
        // =n-1; but we can pick only once
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
        int cherries = grid[r1][c1];
        if (r1 != r2 || c1 != c2) {
            cherries += grid[r2][c2];
        }
        
        int ans = max(
            max(helper(grid, r1 + 1, c1, r2 + 1,dp), helper(grid, r1 + 1, c1, r2,dp)),
            max(helper(grid, r1, c1 + 1, r2 + 1,dp),helper(grid, r1, c1 + 1, r2,dp))
            );

        return dp[r1][c1][r2] = ans + cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));

        int res =  helper(grid, 0, 0, 0,dp);
        return max(0,res);
    }
};
