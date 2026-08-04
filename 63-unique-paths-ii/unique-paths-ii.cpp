class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<int>prev(n,0);

        for(int col =0; col<n; col++){
            if(obstacleGrid[0][col] == 1) break;
            prev[col] = 1;
        }
        
        for(int i =1;i<m;i++){
            vector<int>curr(n,0);
            for(int j =0;j<n;j++){
                if(obstacleGrid[i][j] != 1){
                    if(j ==0)
                        curr[j] = prev[j];
                    else
                        curr[j] = curr[j-1]+prev[j];
                    
                }
            }
            prev = curr;
        }

        return prev[n-1];
        
    }
};