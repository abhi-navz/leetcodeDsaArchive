class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // making adjacency list 

        vector<vector<pair<int,int>>> adj(n+1); // u->{v, weight}

        for(auto time :times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v,w});
        }

        // min heap {dist, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        const int INF = 1e9;
        vector<int>dis(n+1,INF);

        dis[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            auto[d,u] = pq.top();
            pq.pop();
            
            if (d > dis[u]) continue; // stale entries, if i already have dis[u] lesser than d, why do i need it?

            for(auto edge: adj[u]){
                int v = edge.first;
                int w = edge.second;

                if(dis[u]+w < dis[v]){
                    dis[v] = dis[u]+w;
                    pq.push({dis[v], v});

                }
            }
        }

        int minTime = 0;

        for(int i =1; i<n+1; i++){
            if(dis[i] == INF){
                return -1;
            }

            minTime = max(minTime, dis[i]);
        }


        return minTime;

    }
};
