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

    int dfs(TreeNode* root, int &mps){
        if(!root)return 0;

        int leftMps = max(0,dfs(root->left,mps));
        int rightMps = max(0,dfs(root->right,mps));

        int currentMps = root->val+leftMps +rightMps;
        mps = max(mps,currentMps);

        return root->val + max(leftMps,rightMps);

    }
    int maxPathSum(TreeNode* root) {

        int mps = INT_MIN;
        dfs(root, mps);
        return mps;
       


        
    }
};
