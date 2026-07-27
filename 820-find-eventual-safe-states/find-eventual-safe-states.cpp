class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&path, vector<int>&safe){

        path[node] = 1;
        vis[node] = 1;

        for(int next:adj[node]){
            if(!vis[next]){
                if(!dfs(next,adj,vis,path,safe)) return false;
            }else{
                if(path[next]){
                    return false;
                }
            }
            
        }
        safe[node] = 1;
        path[node] = 0;
        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>ans;

        vector<int>vis(V,0);
        vector<int>path(V,0);
        vector<int>safe(V,0);

        for(int i=0;i<V; i++){
            if(!vis[i]){
               dfs(i,graph,vis,path,safe);
            }
        }

        for(int i=0; i<V; i++){
            if(safe[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};