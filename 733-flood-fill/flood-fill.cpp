class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size();
        int n = image[0].size();

        int oc = image[sr][sc];
        if(oc == color) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;

        int dir[4][2] ={{-1,0}, {1,0}, {0,-1},{0,1}};

        while(!q.empty()){
            auto[row,col] = q.front();
            q.pop();

            for(auto &d : dir){
                int nr = row+d[0];
                int nc = col+d[1];

                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc] == oc){
                    image[nr][nc] = color;
                    q.push({nr,nc});
                }
            }
        }

        return image;
    }
};