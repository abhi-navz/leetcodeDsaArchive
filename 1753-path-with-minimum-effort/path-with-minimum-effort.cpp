class Solution {
public:
    int INF = 1e9;
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<int>> dist(m, vector<int>(n, INF));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q; // {maxeffort , {row, col}};

        q.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!q.empty()) {
            auto it = q.top();
            q.pop();

            int currEffort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(currEffort > dist[row][col]) continue;

            for (auto& d : dir) {
                int nr = row + d[0];
                int nc = col + d[1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int newEffort = max(
                        currEffort, abs(heights[row][col] - heights[nr][nc]));

                    if (dist[nr][nc] > newEffort) {
                        dist[nr][nc] = newEffort;
                        q.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};