class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();
        vector<int> vis(V, 0);
        int count = 0;
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                q.push(i);
                vis[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int j =0; j<V; j++) {
                        if(isConnected[node][j] && !vis[j]){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};