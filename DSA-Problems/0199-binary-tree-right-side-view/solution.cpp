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

        // a map data structure to store the node val based on the levels

        map<int,int> m;

        // queue data structure for level order traversal 
        queue<pair<TreeNode* , int > > q;

        q.push({root, 0});
        while(!q.empty()){

            TreeNode* curr = q.front().first;
            int currLevel = q.front().second;

            q.pop();

            if(curr->left) q.push({curr->left, currLevel+1});
            if(curr->right) q.push({curr->right , currLevel+1});

            m[currLevel] = curr->val;
        }

        for(auto it: m){
            ans.push_back(it.second);
        }

        return ans;

    
        
    }
};
