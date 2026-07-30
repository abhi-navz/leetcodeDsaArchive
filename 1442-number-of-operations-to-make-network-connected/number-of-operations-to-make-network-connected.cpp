class Solution {
public:
    void bfs(int node, vector<int>&vis, const vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int nxt : adj[curr]){
                if(!vis[nxt]){
                    vis[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int cabels = connections.size();
        if(cabels < n-1) return -1;

        vector<vector<int>>adj(n);
        for(const auto &cable : connections){

            int u = cable[0];
            int v  = cable[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(n,0);

        int components = 0;
        for(int i =0; i<n; i++){
            if(!vis[i]){
                components++;
                bfs(i, vis,adj);
            }
        }
        

        return components -1;


    }
};