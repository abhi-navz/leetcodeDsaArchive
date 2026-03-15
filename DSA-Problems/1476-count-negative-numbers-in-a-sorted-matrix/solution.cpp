class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int n = grid.size(); // row
        int m = grid[0].size();  // col
        
        int row = 0;
        int col = m - 1;
        int count = 0;
        
        while(row < n && col >= 0){
            
            if(grid[row][col] < 0){
                count += (n - row);
                col--;
            }
            else{
                row++;
            }
        }
        
        return count;


        
    }
};
