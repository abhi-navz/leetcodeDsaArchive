class Solution {
public:
    int INF = 1e9;
    int minimumTime(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if (m > 1 && n > 1 && grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        vector<vector<int>> dist(m, vector<int>(n, INF));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // {time , {row,col}};

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // starting from {0.0};

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            cout << it.first << ",";
            pq.pop();

            int t = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == m - 1 && col == n - 1)
                return dist[row][col];

            if (t > dist[row][col])
                continue; // removing stale.

            for (auto& d : dir) {
                int nr = row + d[0];
                int nc = col + d[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int g = grid[nr][nc];
                    int nt = 0;
                    if (t + 1 >= g) {
                        nt = t + 1;
                    } else {
                        int diff = (g - t);
                        if (diff % 2 == 1) {
                            nt = g;
                        } else {
                            nt = g + 1;
                        }
                    }

                    if (nt < dist[nr][nc]) {
                        dist[nr][nc] = nt;
                        pq.push({nt, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};