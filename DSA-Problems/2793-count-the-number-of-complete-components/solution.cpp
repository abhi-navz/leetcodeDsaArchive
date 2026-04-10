class Solution {
public:
    int bfs(int n, vector<vector<int>>& adj) {
       int count =0;

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {

            

            if (!vis[i]) {
                // a component starts
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                int compVertex = 0;;
                int compEdges = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    compVertex++;
                    compEdges += adj[node].size();
                    for (int nbr : adj[node]) {
                        if (!vis[nbr]) {
                            vis[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }

                if(compEdges/2 == compVertex*(compVertex-1)/2) count++;
                
            }
        }
        return count;

        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return bfs(n,adj);
    }
};
