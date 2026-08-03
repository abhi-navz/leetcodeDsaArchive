class Solution {

    unordered_map<int, int> pos;

public:
    bool helper(int idx, int k, vector<int>& stones, vector<vector<int>>& dp) {
        int n = stones.size();
        if (idx == n - 1)
            return true;

        if (dp[idx][k] != -1) {
            return dp[idx][k]; // {0,1} false or true
        }

        for (int j = -1; j <= 1; j++) {
            int jump = k + j;
            if (jump <= 0)
                continue;

            int nextPos = stones[idx] + jump;
            if (pos.count(nextPos)) {
                if (helper(pos[nextPos], jump, stones, dp))
                    return dp[idx][k] = true;
            }
        }

        return dp[idx][k] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            pos[stones[i]] = i;
        }

        if (stones[1] != 1)
            return false;

        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        dp[1][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n + 1; j++) {

                if (dp[i][j] == 1) {
                    for (int a = -1; a <= 1; a++) {
                        int jump = j + a;
                        if (jump <= 0)
                            continue;
                        int np = stones[i] + jump;
                        if (pos.count(np)) {
                            dp[pos[np]][jump] = 1;
                        }
                    }
                }
            }
        }

        for(int j = 0; j<n+1; j++){
            if(dp[n-1][j] == 1) return true;
        }
        return false;
    }
};