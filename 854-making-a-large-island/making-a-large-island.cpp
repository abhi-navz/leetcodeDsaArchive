class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUP(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUP(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUP(u);
        int pv = findUP(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        bool hasZero = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    break;
                }
            }
            if (hasZero)
                break;
        }
        if (!hasZero)
            return n * n;

            
        DisjointSet ds(n * n);

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Build DSU for all existing 1's
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int adjNode = nr * n + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        // Try flipping each 0
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1)
                    continue;

                unordered_set<int> parents;
                int currSize = 1;

                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int p = ds.findUP(nr * n + nc);

                        if (!parents.count(p)) {
                            currSize += ds.size[p];
                            parents.insert(p);
                        }
                    }
                }

                ans = max(ans, currSize);
            }
        }

        return ans;
    }
};