class Solution {
public:
    void dfs(int node, int n, vector<vector<int>>& adj, vector<int>& curr,
             vector<vector<int>>& ans) {

        curr.push_back(node);
        if (node == n - 1) {
            ans.push_back(curr);
            curr.pop_back();
            return;
        }

        for (int nextNode : adj[node]) {
            dfs(nextNode, n, adj, curr, ans);
        }

        curr.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans;
        vector<int>curr;

        dfs(0,n,graph,curr,ans);
        return ans;
    }
};