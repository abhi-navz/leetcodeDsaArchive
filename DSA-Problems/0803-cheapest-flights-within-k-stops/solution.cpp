class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n); // u->{v,p}

        for (auto flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];

            adj[u].push_back({v, p});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);

        q.push({0, {0, src}});
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int cost = it.second.first;
            int node = it.second.second;

            if (stops <= k) {
                for (auto adjNode : adj[node]) {
                    int nextNode = adjNode.first;
                    int price = adjNode.second;

                    if (dist[nextNode] > cost + price) {
                        dist[nextNode] = cost + price;
                        q.push({stops + 1, {cost + price, nextNode}});
                    }
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
