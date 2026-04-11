class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {

        int n = bombs.size();

        // we are given n bombs with their pos and their radius
        // we'll build adjacency list of each bombs, where it'll contains the next bombs it
        // can detonate by its explosion
        vector<vector<int>>adj(n);
        for(int i =0; i<n; i++){

            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long rad = bombs[i][2];

            // checking other bombs if they are in area of this bomb

            for(int j =0; j<n; j++){
                if(i == j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long  dx = x1-x2;
                long long dy = y1-y2;

                if(dx*dx + dy*dy <= rad*rad){
                    adj[i].push_back(j);
                }

            }
        }

        // now we'll use this adjacency list to see no of bombs that can be detonated by each bomb explosion

        int maxBombEx = 0;

        for(int i =0; i<n; i++){
            vector<int>vis(n,0);
            queue<int>q;
            vis[i] = 1;
            q.push(i);
            int bombEx = 1;

            while(!q.empty()){
                int bomb = q.front();
                q.pop();

                for(int x: adj[bomb]){
                    if(!vis[x]){
                        vis[x] = 1;
                        bombEx++;
                        q.push(x);
                    }
                }
            }
            
            maxBombEx = max(maxBombEx, bombEx);
        }

        return maxBombEx;
        
    }
};
