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
    TreeNode* helper(vector<int>&arr, int st, int end){
        if(st>end) return nullptr;

        TreeNode* root = new TreeNode(arr[st]);
        int i = st+1;

        while(i<= end && arr[i] < arr[st]){
            i++;
        }

        root->left = helper(arr,st+1, i-1);
        root->right = helper(arr, i,end);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int st =0;
        int end = preorder.size()-1;

        return helper(preorder,st,end);
        
    }
};
