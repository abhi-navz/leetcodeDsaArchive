class Solution {
public:
    int topoSort(int V, vector<int>&indegree, vector<vector<int>>&adj){
      queue<int>q;
      int sz=0;
      
      for(int i =0; i<V; i++){
          if(indegree[i] == 0){
              q.push(i);
            }
        }
       
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           sz++;
           
           for(int adjNode :adj[node]){
               indegree[adjNode]--;
               if(indegree[adjNode] == 0){
                   q.push(adjNode);
               }
           }
       }
       
       return sz;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto course : prerequisites){
            int u = course[1];
            int v = course[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        int topoSize = topoSort(numCourses, indegree, adj);
        return (topoSize == numCourses);
    }
};
