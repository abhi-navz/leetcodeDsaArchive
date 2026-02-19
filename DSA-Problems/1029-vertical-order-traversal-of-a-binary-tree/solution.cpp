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

        // queue data structure to traverse;

        queue<pair<TreeNode*, pair<int, int>>> q; // {node,{hd,lvl}};

        // map datastructure to hold the values

        map <int,map<int,vector<int>>> mpp;


        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int hd = it.second.first;
            int lvl = it.second.second;

            mpp[hd][lvl].push_back(node->val);

            if(node->left){
                q.push({node->left,{hd-1,lvl+1}});
            }
            if(node->right){
                q.push({node->right,{hd+1,lvl+1}});
            }
        }

        // map contains data mpp(hd, mpp2)
        // mpp2(lvl, vector)
        // vecotr [node->val];

        vector<vector<int>>ans;

        for(auto &p: mpp){
            vector<int>col;

            for(auto &q : p.second){
               
                sort(q.second.begin(), q.second.end());
                for(int x: q.second){
                    col.push_back(x);
                }
            }
            ans.push_back(col);
        }

        return ans;



    }
};
