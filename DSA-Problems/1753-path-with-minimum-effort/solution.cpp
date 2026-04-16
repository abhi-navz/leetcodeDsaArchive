class Solution {
public:
    int INF = 1e9;
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>dist(m,vector<int>(n,INF));

        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>>pq; // {maxEffortSoFar, {row,col}};

        pq.push({0,{0,0}});
        dist[0][0] = 0;


        int dirs[4][2]= {{0,1}, {0,-1}, {-1,0}, {1,0}};

        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
            int maxEffort = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(maxEffort > dist[x][y]) continue;

            if(x == m-1 && y == n-1) return maxEffort;

            for(auto dir : dirs){
                int nx = x +dir[0];
                int ny = y +dir[1];

                if(nx>=0 && nx<m && ny>=0 && ny<n){

                    int effort = abs(heights[nx][ny] - heights[x][y]);
                    int newEffort = max(maxEffort,effort);

                    if(newEffort < dist[nx][ny]){
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort,{nx,ny}});
                    }
                }
            }


        }

        return INF;
        
    }
};
