class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& adj, vector<int>& vis,
                 vector<int>& path) {
        vis[node] = 1;
        path[node] = 1;

        for (int adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (isCycle(adjNode, adj, vis, path))
                    return true;
            } else if (path[adjNode])
                return true;
        }
        path[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            adj[b].push_back(a);
        }

        vector<int> path(numCourses, 0);
        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycle(i, adj, vis, path))
                    return false;
            }
        }
        return true;
    }
};