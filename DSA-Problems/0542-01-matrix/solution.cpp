class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>>q; // {i,j};

        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){

                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        int dirs[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
        vector<vector<int>>vis(m, vector<int>(n,0));

        while(!q.empty()){
            auto[x,y] = q.front();
            q.pop();

            for(auto &d : dirs){
                int nx = x+d[0];
                int ny = y+d[1];

                if(nx >= 0 && nx < m && ny>= 0 && ny<n && mat[nx][ny] == 1 && vis[nx][ny] == 0){

                    q.push({nx,ny});
                    vis[nx][ny] = 1;
                    mat[nx][ny] = mat[x][y]+1;

                }
            }
        }

        return mat;
    }
};
