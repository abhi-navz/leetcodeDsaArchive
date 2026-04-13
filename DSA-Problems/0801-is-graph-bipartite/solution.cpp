class Solution {
public:
    bool dfs(int node, int color, vector<int>&col, vector<vector<int>>&graph)
    {   
        col[node] = color;

        for(int adjacentNode : graph[node]){
            if(!col[adjacentNode]){
                if(!dfs(adjacentNode, -color, col,graph)){
                    return false;
                }
            }else{
                if(col[adjacentNode] == color) return false;
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        // using dfs to do it
        int V = graph.size();
        vector<int>col(V,0);

        for(int i=0; i<V; i++){
            if(!col[i]){
               if(!dfs(i,1,col, graph)){
                return false;
               }
            }
        }
        return true;


        
    }
};
