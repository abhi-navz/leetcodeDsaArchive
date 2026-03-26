class Solution {
public:
    bool helper(vector<int>& stones, int currPos, unordered_map<int, int>& mpp,
                int jump, vector<vector<int>>& dp) {
        int n = stones.size();
        // base case
        if (currPos == n - 1) return true;

        if (dp[currPos][jump] != -1) return dp[currPos][jump];

        int currStone = stones[currPos];

        for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {

            if (nextJump <= 0) continue;

            int nextStone = currStone + nextJump;

            if (mpp.find(nextStone) != mpp.end()) {

                int nextPos = mpp[nextStone];

                if (helper(stones, nextPos, mpp, nextJump, dp)) {
                    return dp[currPos][jump] = true;
                }
            }
        }

        return dp[currPos][jump] = false;
    }
    bool canCross(vector<int>& stones) {
        if (stones[0] + 1 != stones[1])
            return false;
        int n = stones.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[stones[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(stones, 0, mpp, 0, dp);
    }
};
