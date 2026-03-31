class Solution {
public:
    int n;
    int m; 
    int helper(vector<vector<int>>&a,int i, int j1, int j2,vector<vector<vector<int>>>&dp){

        // base cases 
        // out of bound;
        if(j1<0 || j1>=m ||j2<0 ||j2>=m)return -1e9;

        // last row
        if(i == n-1){
            if(j1 == j2){
                return a[i][j1];
            }else{
                return a[i][j1]+a[i][j2];
            }
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = 0;
        for(int dj1 = -1; dj1<=1; dj1++){
            for(int dj2 = -1; dj2<=1; dj2++){
                if(j1 == j2){
                    maxi = max(maxi,a[i][j1]+helper(a,i+1,j1+dj1,j2+dj2,dp));
                }else{
                    maxi = max(maxi,a[i][j1]+a[i][j2]+helper(a,i+1,j1+dj1,j2+dj2,dp));
                }
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));

        return helper(grid,0,0,m-1,dp);
    }
};
