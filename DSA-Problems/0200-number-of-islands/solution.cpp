class Solution {
public:
    int m, n;

    void bfs(int i, int j, vector<vector<char>>& grid) {

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        bfs(i - 1, j, grid);
        bfs(i + 1, j, grid);
        bfs(i, j - 1, grid);
        bfs(i, j + 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int isLands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    isLands++;
                    bfs(i, j, grid);
                }
            }
        }

        return isLands;
    }
};
