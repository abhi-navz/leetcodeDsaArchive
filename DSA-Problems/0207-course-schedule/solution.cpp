class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];

            indegree[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

       int topo =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo == numCourses ){
            return true;
        }

        return false;
    }
};
