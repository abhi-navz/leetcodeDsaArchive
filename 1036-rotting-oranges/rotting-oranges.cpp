class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q; //{row, col}

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        int time = 0;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1)fresh++;
            }
        }

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;

                for (int j = 0; j < 4; j++) {
                    int nextRow = row + dr[j];
                    int nextCol = col + dc[j];

                    if (nextRow >= 0 && nextRow < m && nextCol >= 0 &&
                        nextCol < n && grid[nextRow][nextCol] == 1) {
                        q.push({nextRow, nextCol});
                        grid[nextRow][nextCol] = 2; // rotting an orange
                        fresh--; 
                    }
                }
            }
            if (!q.empty())
                time++;
        }

        // checking there's no fresh
        
        return (fresh == 0)? time : -1;
    }
};