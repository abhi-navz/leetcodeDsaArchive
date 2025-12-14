class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // making adjacency list and indegree array 

        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);

        for(auto edge: prerequisites){
            int u = edge[1];
            int v = edge[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int>topo;
        queue<int>q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int v : adj[node]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }

        return topo.size() == numCourses ? true: false;


        
    }
};
