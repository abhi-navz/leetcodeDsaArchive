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
        if(!root) return 0;
        long long maxWidth = 0;

        queue<pair<long long,TreeNode*>>q; // {idx, node}

        q.push({0,root});

        while(!q.empty()){

            long long sz = q.size();
            long long minIdx = q.front().first;
            long long  firstIdx,lastIdx;
            for(long long i =0; i<sz; i++){
                auto it = q.front(); 
                q.pop();
                long long idx = it.first;
                idx = idx-minIdx;
                TreeNode* node = it.second;
                if(i ==0) firstIdx = idx;               
                if(i == sz-1) lastIdx = idx;
                if(node->left){
                    q.push({2*idx+1, node->left});
                }
                if(node->right){
                    q.push({2*idx+2, node->right});
                }

            }

            maxWidth = max( maxWidth , lastIdx-firstIdx+1);


        }

        return (int)maxWidth;
    }
};