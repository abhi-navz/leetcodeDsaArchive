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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidth = 0;
        if(!root){
            return 0;
        }

        queue<pair<TreeNode*,long long>>q; // {node, idx};

        q.push({root,0}); // assignning the root idx = 0;

        while(!q.empty()){
            
            int size = q.size();
            long long minIdx = q.front().second; // to normalize the index by substraction
            long long first, last;

            for(int i =0; i<size; i++){
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                long long idx = it.second;

                idx = idx-minIdx; 
                if(i==0) first = idx;
                if(i == size-1) last = idx;
                
               
                if(node->left){
                    q.push({node->left,2*idx});
                }
                if(node->right){
                    q.push({node->right,2*idx+1});
                }
            }

            
            maxWidth = max(maxWidth, (last-first+1));
        }
        
        return maxWidth;
        
    }
};
