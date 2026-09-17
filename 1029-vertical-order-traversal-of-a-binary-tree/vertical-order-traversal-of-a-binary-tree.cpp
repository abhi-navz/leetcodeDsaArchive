/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        if(!root) return ans;

        // queue ds for level order traversal

        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {hd,lvl}};

        // map data structure
        map<int, map<int, vector<int>>> mp; // hd->lvl->{nodes}

        q.push({root,{0,0}});

        while(!q.empty()){

            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int hd = it.second.first;
            int lvl = it.second.second;

            mp[hd][lvl].push_back(node->val);

            if(node->left){
                q.push({node->left,{hd-1, lvl+1}});
            }

            if(node->right){
                q.push({node->right, {hd+1, lvl+1}});
            }
        }

        // generating answer from map now

        for(auto &p : mp){
            vector<int>col;

            for(auto &q : p.second){

                vector<int>nodes = q.second;
                sort(nodes.begin(), nodes.end());
                col.insert(col.end(), nodes.begin(), nodes.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};