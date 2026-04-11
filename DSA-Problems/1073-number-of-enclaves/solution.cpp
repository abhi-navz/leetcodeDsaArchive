class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;

        // pushing the zeros at the boundaries

        for(int i =0; i<m; i++){

            if(grid[i][0] == 1){
                grid[i][0] = 0;
                q.push({i,0});
            }
            if(grid[i][n-1] == 1){
                grid[i][n-1] = 0;
                q.push({i,n-1});
            }

        }

        for(int j=0; j<n; j++){
            if(grid[0][j] == 1){
                grid[0][j] = 0;
                q.push({0,j});
            }
            if(grid[m-1][j] == 1){
                grid[m-1][j] = 0;
                q.push({m-1,j});
            }
        }

        int directions[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto &dir : directions ){
                int nx = x +dir[0];
                int ny = y +dir[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1){
                    grid[nx][ny] = 0;
                    q.push({nx,ny});
                }
            }
        }

        int noOfEnclaves = 0;
        for(int i =0;i<m; i++){
            for(int j =0; j<n; j++){

                if(grid[i][j] == 1 ){
                    noOfEnclaves++;
                }
            }
        }
        
        return noOfEnclaves;
    }
};
