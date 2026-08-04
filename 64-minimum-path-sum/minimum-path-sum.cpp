class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
		
		vector<int>prev(n);
        prev[0] = grid[0][0];
        for(int col = 1; col<n; col++){
            prev[col] = prev[col-1]+grid[0][col];
        }
		
		
		for (int i = 1; i<m; i++) {
			vector<int>curr(n);
            for(int j =0; j<n ; j++){
                if(j == 0)  
                    curr[j] = prev[j]+grid[i][j];
                else{
                    curr[j]  = grid[i][j] + min (curr[j-1], prev[j]);
                }    
            }	
			prev = curr;
		}
		
		// return ans;
	
		return prev[n-1];
    }
};