class Solution {
public:
    vector<int> topoSort(int V, vector<int>& indegree,
                         vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int adjNode : adj[node]) {
                indegree[adjNode]--;
                if (indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        return ans;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto course : prerequisites) {
            int u = course[1];
            int v = course[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<int> ans = topoSort(numCourses, indegree, adj);

        if (ans.size() == numCourses)
            return ans;
        return {};
    }
};
