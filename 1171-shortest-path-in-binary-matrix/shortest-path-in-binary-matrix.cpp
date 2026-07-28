class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[n-1][n-1] == 1 || grid[0][0] == 1) return -1;

        int dir[8][2] = {{-1,0}, {1,0}, {0,-1}, {0,1},{-1,-1},{-1,1},{1,-1},{1,1}};

        queue<pair<int,int>>q; // {row,col};
        vector<vector<int>>vis(n, vector<int>(n,0));

        q.push({0,0});
        grid[0][0] = 1;

        int lvl = 0;
        while(!q.empty()){
            lvl++;
            int sz = q.size();
            while(sz--){
                auto[row,col] = q.front();
                if(row == n-1 && col == n-1) return lvl;
                q.pop();

                for(auto &d : dir){
                    int nr = row+d[0];
                    int nc = col+d[1];

                    if( nr>=0 && nr<n && nc>=0 && nc<n && !grid[nr][nc]){
                        grid[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }

        } 
        return -1;      

       
    }
};