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
    void dfs(int lvl, TreeNode* root, vector<int>&ans){
        if(!root) return;
        if(lvl == ans.size()){
            ans.push_back(root->val);
        }

        if(root->right){
            dfs(lvl+1, root->right, ans);
        }
        if(root->left){
            dfs(lvl+1, root->left, ans);
        }

    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        dfs(0,root,ans);

        return ans;
    }
};