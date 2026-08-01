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
        ans[lvl] = root->val;
        if(root->left){
            dfs(lvl+1, root->left, ans);
        }
        if(root->right){
            dfs(lvl+1, root->right, ans);
        }

    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>temp(100,-200);
        dfs(0,root,temp);

        
        vector<int>ans;
        for(int x: temp){
           
            if(x == -200) break;
            ans.push_back(x);
        }

        return ans;
        

    }
};