class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<int,int>>q;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        // pushing the zeros into the q;
        for(int i =0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                if(mat[i][j] == 1){
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            for(auto &d : dir){
                int nr = row+d[0];
                int nc = col+d[1];

                if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && mat[nr][nc] == -1){
                    mat[nr][nc] = 1+mat[row][col];
                    q.push({nr,nc});
                }
            }
        }
        return mat;
    }
};