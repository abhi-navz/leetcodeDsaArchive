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

        queue<pair<TreeNode*, int>> q; // node, vertical Distance
        map<int,int> mpp; // vd, node

        q.push({root,0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int currentVd = q.front().second;

            q.pop();
            if(node->left)
                q.push({node->left, currentVd+1});
            if(node->right)
                q.push({node->right, currentVd+1});   

            
            mpp[currentVd] = node->val; //update to get right side view value
           


        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }

        return ans;
        
    }
};
