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
    vector<int> rightSideView(TreeNode* root) {

        vector<int>ans;
        if(!root) return ans;
        // queue structure;
        queue<pair<TreeNode*,int>> q ;// root, lvl;
        map<int,int> mpp;

        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int lvl = it.second;

            mpp[lvl] = node->val;
            if(node->left){
                q.push({node->left, lvl+1});
               
            }
            if(node->right){
                q.push({node->right,lvl+1});
            }
        }
        
        for(auto &p : mpp){
            ans.push_back(p.second);
        }

        return ans;
    }
};
