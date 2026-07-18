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
    void helper(TreeNode* root, string &currPath, vector<string>&ans){
        if(!root) return ;

        int len = currPath.size();
        if(!currPath.empty()){
            currPath += "->";
        }
        currPath += (to_string(root->val));

        if(!root->left && !root->right){
            ans.push_back(currPath);
        }else{
            helper(root->left, currPath, ans);
            helper(root->right,currPath, ans);
        }

        currPath.resize(len); // removing everything we added 

        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr = "";

        helper(root,curr, ans);
        return ans;
    }
};