class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();   
        vector<int>vis(V, 0);
        queue<pair<int,int>>q; // {node , color}; color {1->red, 2->blue};

        for(int i =0; i<V; i++){
            if(!vis[i]){
                vis[i] = 1; // red;
                q.push({i,1});
            }

            while(!q.empty()){
                auto[node, color] = q.front(); q.pop();
                for(int adjNode : graph[node]){
                    if(!vis[adjNode]){
                        if(color == 1)vis[adjNode] = 2;
                        else vis[adjNode] = 1;
                        q.push({adjNode, vis[adjNode]});      
                    }else if(vis[adjNode] == color){
                        return false;
                    }
                }
            }
        }
        return true;

    }
};