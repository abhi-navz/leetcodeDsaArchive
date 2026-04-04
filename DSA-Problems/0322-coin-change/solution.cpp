class Solution {
public:
    int n;
    int INF = 1e9;
    int coinChange(vector<int>& coins, int amount) {

        n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        for (int i = 0; i < n; i++)
            dp[i][0] = 0;

        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                dp[0][amt] = amt / coins[0];
        }

        for (int idx = 1; idx < n; idx++) {
            for (int amt = 0; amt <= amount; amt++) {

                int notTake = dp[idx - 1][amt];
                int take = INF;

                if (amt - coins[idx] >= 0) {
                    take = 1 + dp[idx][amt - coins[idx]];
                }

                dp[idx][amt] = min(take, notTake);
            }
        }

        int ans =  dp[n - 1][amount];
        return (ans>= INF)? -1 : ans;
    }
};
