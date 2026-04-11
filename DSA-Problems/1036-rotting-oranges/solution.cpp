class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>> q;

        // pushing into queue and counting fresh oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int minutes = 0;
        int dir[4][2] = {{0,-1},{0,1}, {1,0},{-1,0}}; // shorthand to check all diretion by looping

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();

                // rotting the neighbours

                for(auto &d : dir){
                    int nx = x+d[0];
                    int ny = y+d[1];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny] == 1){
                        fresh --;
                        grid[nx][ny] = 2;

                        q.push({nx,ny});
                    }
                }

            }
        }

        if(fresh == 0 ) return minutes;
        else return -1;
    }
};
