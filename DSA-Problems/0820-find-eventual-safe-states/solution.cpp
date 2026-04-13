class Solution {
public:
    bool dfs (int node, vector<int>&vis, vector<int>&path, vector<vector<int>>&adj){
        vis[node] = 1;
        path[node] = 1;

        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, path, adj)){
                    return true;
                }
            }else{
                if(path[adjNode] == 1)
                    return true;
            }
        }

        path[node] = 0; // exiting the node from path 

        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> ans;

        // the nodes which are not safe will eventually go into cycle so i'll
        // have to check which nodes deoesn't form a cycle.

        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        for (int i = 0; i < V; i++) {

            if (!dfs(i, vis, path, graph)) {
                ans.push_back({i});
            }
        }

        return ans;
    }
};
