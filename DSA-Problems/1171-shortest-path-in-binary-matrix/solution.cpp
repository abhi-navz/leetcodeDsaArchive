class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        // we can solve it using bfs

        int m = grid.size();
        int n = grid[0].size();
        // if the first cell (0,0) is not 0 or the last cell (m-1,n-1) is not 0

        if (grid[0][0] != 0 || grid[m - 1][n - 1] != 0)
            return -1;

        int len = 0;
        queue<pair<int, int>> q; //{i,j}

        q.push({0, 0});
        grid[0][0] = 2; // visited

        int dirs[8][2] = {
            {-1, -1},
            {-1, 1},
            {1, 1},
            {1, -1},
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0}
        };

        while(!q.empty()){
            
            int lvlSize = q.size();
            len++;
            for(int i =0; i<lvlSize; i++){
                auto[x,y] = q.front(); q.pop();

                if(x == m-1 && y == n-1){
                    return len;
                }

                for(auto dir : dirs){
                    int nx = x+dir[0];
                    int ny = y+dir[1];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 0){
                        q.push({nx,ny});
                        grid[nx][ny] = 2;
                    }
                    
                }
            }
        }

        return -1;
    }
};
