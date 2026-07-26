class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>&img,int row, int col, int oc, int color){
        int m = img.size();
        int n = img[0].size();
        img[row][col] = color;
        for(auto &d : dir){
            int nr = row+d[0];
            int nc = col +d[1];

            if(nr>=0 && nr<m && nc>=0 && nc<n && img[nr][nc] == oc){
                dfs(img,nr,nc,oc,color);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oc = image[sr][sc];
        if(oc == color) return image;

        dfs(image,sr,sc,oc,color);
        return image;
    }
};