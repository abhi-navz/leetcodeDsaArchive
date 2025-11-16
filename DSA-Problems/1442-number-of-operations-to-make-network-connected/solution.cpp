class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        int cables = connections.size();

        // to conncect n pcs, i'll need minimum of n-1 cables. so if i don't
        // have atleast n-1 cables i can't connect all the pcs.

        if (cables < n - 1) {
            return -1;
        }

        // to connect k components together i'll need k -1 min cables , so if
        // there are more than k-1 cabels avialbe i can say no of operation will
        // be k=1 to conncect all pcs.
        // couting no of components. we cand do it by using bfs

        // creating adjacency list;
        vector<vector<int>> adj(n);

        for (auto cable : connections) {
            int u = cable[0];
            int v = cable[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        queue<int> q;

        int comps = 0;

        
        for (int st = 0; st < n; st++) {
            if (!vis[st]) {
                comps++;
                // vector<int> comp; // i don't need this vector for my answer, i don't need to build it
                vis[st] = 1;
                q.push(st);

                while (!q.empty()) {
                    int u = q.front();
                    // comp.push_back(u);
                    q.pop();

                    for (int it : adj[u]) {

                        if (!vis[it]) {
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }

              
            }
        }

       
        return comps-1;


    }
};
