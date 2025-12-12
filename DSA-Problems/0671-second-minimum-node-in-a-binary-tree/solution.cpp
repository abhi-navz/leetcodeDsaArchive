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
   
    long long ans = LONG_LONG_MAX;
    void dfs(TreeNode* root,int min1 ){

        if(!root) return;
        if(root->val > min1 && root->val < ans){
            ans = root->val;
        }
        dfs(root->left,min1);
        dfs(root->right, min1);
       
    }
    int findSecondMinimumValue(TreeNode* root) {
       int  min1 = root->val;
        dfs(root,min1);
        if(ans == LONG_LONG_MAX ) return -1;
        return ans;

        
    }
};
