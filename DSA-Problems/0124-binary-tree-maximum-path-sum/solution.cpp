/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int mps = INT_MIN;
    int dfs(TreeNode* root) {
        if(!root) return 0;

        int leftMps =  max(0, dfs(root->left));
        int rightMps = max(0,dfs(root->right));

        int currentMps = root->val + leftMps + rightMps;

        mps = max(currentMps, mps);
        // can return only one branch along with root
        return root->val + max(leftMps, rightMps);
    
    }

    int maxPathSum(TreeNode* root){
        dfs(root);
        return mps;
    }
};
