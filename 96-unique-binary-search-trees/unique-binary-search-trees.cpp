class Solution {
public:
    int numTrees(int n) {

        // for every possible root, the no of leftNodes will be from 1->root-1
        // and rightNodes will be from root+1, n

        // for n = 5 and root = 3
        // leftNodes = 1,2 and rightNodes = 4, 5

        // no of left nodes 3-1(root -1) = 2
        // no of right nodes 5-3(n-root) = 2

        // and total trees that can be formed using 3 as root is no of tress
        // from left i.e. dp[leftNodes] * no of tree from right i.e
        // dp[ightNodes] i.e. 2*2 = 4

        // base case if n =0 we could form a empty tree
        // if n ==1 then we have one tree.

        vector<int> dp(n + 1, 0);
        // base case
        dp[0] = 1;
        dp[1] = 1;
        for (int nodes = 2; nodes <= n; nodes++) {

            for (int root = 1; root <= nodes; root++) {
                int left = root - 1;
                int right = nodes-root;

                dp[nodes]+= dp[left]*dp[right];
            }
        }

        return dp[n];
    }
};