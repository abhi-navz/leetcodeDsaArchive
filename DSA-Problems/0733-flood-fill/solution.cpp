class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {


        int m = image.size();
        int n = image[0].size();

        int oc = image[sr][sc];
        if(oc == color) return image;

        queue<pair<int,int>>q;
        image[sr][sc] = color;

        q.push({sr,sc});

        int dirs[4][2] = {{0,-1}, {0,1},{-1,0}, {1,0}};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dirs){
                int nx = x+d[0];
                int ny = y + d[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny] == oc){
                    
                    image[nx][ny] = color;
                    q.push({nx,ny});
                }
            }
        }

        return image;
        
    }
};
