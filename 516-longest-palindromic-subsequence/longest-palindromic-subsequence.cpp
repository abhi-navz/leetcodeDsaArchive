class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][i] = 1;
        }

        for (int st = n - 1; st >= 0; st--) {
            for (int end = st + 1; end < n; end++) {

                if (s[st] == s[end]) {
                    dp[st][end] = 2 + dp[st + 1][end - 1];
                } else {
                    dp[st][end] = max(dp[st + 1][end], dp[st][end - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};