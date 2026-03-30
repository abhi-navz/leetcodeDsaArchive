class Solution {
public:
   
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(n, INF));

        int ans = INT_MAX;

        for (int row = n - 1; row >= 0; row--) {
            for (int col = 0; col < n; col++) {

                if (row == n - 1) {
                    dp[row][col] = matrix[row][col];

                } else {

                    int below = dp[row + 1][col];
                    int leftDiag = INT_MAX, rightDiag = INT_MAX;
                    if (col - 1 >= 0)
                        leftDiag = dp[row + 1][col - 1];
                    if (col + 1 <= n - 1)
                        rightDiag = dp[row + 1][col + 1];

                    dp[row][col] =
                        matrix[row][col] + min(below, min(leftDiag, rightDiag));
                }
            }
        }

        for(int col = 0; col<n; col++){
            ans = min(ans, dp[0][col]);
        }

        return ans;
    }
};
