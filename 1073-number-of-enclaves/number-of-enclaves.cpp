class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        // pushing and marking the 'O' on edge.

        // rows
        for(int i =0; i<n; i++){
            if(grid[0][i] == 1){
                grid[0][i] = '#';
                q.push({0,i});
            }
            if(grid[m-1][i] == 1){
                grid[m-1][i] = '#';
                q.push({m-1,i});
            }
        }
        // cols
        for(int j =0; j<m; j++){
            if(grid[j][0] == 1){
                grid[j][0] = '#';
                q.push({j,0});
            }
            if(grid[j][n-1] == 1){
                grid[j][n-1] = '#';
                q.push({j,n-1});
            }
        }

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            for(auto &d : dir){
                int nr = row+d[0];
                int nc = col+d[1];

                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1){
                    grid[nr][nc] = '#';
                    q.push({nr,nc});
                }

            }
        }

        int count =0;
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};