class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>>q;
        int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
        // pushing and marking the 'O' on edge.

        // rows
        for(int i =0; i<n; i++){
            if(board[0][i] == 'O'){
                board[0][i] = '#';
                q.push({0,i});
            }
            if(board[m-1][i] == 'O'){
                board[m-1][i] = '#';
                q.push({m-1,i});
            }
        }
        // cols
        for(int j =0; j<m; j++){
            if(board[j][0] == 'O'){
                board[j][0] = '#';
                q.push({j,0});
            }
            if(board[j][n-1] == 'O'){
                board[j][n-1] = '#';
                q.push({j,n-1});
            }
        }

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            for(auto &d : dir){
                int nr = row+d[0];
                int nc = col+d[1];

                if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc] == 'O'){
                    board[nr][nc] = '#';
                    q.push({nr,nc});
                }

            }
        }

        // mark every remainng'0' as 'X'
        for(int i =0; i<m;i++){
            for(int j =0; j<n;j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }

        // restore the "#" to "O"
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};