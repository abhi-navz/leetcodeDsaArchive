class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&path){

        path[node] = 1;
        vis[node] = 0;

        for(int next:adj[node]){
            if(vis[next] == -1){
                if(!dfs(next,adj,vis,path)) return false;
            }else{
                if(path[next]){
                    return false;
                }
            }
            
        }
        path[node] = 0;
        vis[node] = 1;
        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>ans;

        vector<int>vis(V,-1); // {-1: not visited, 0: visited , 1: visited and marked safe}
        vector<int>path(V,0);
        

        for(int i=0;i<V; i++){
            if(vis[i] == -1){
               dfs(i,graph,vis,path);
            }
        }

        for(int i=0; i<V; i++){
            if(vis[i] == 1) ans.push_back(i);
        }

        return ans;
    }
};