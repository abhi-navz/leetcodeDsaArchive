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
    TreeNode* helper(int st, int end, vector<int>&nums){

        if(st>end){
            return nullptr;
        }

        int maxi = nums[st];
        int rootIdx = st;
        for(int i = st+1; i<=end; i++){
            if(nums[i]> maxi){
                maxi = nums[i];
                rootIdx = i;
            }
        }

        TreeNode *root = new TreeNode(maxi);
        root->left = helper(st, rootIdx-1,nums);
        root->right = helper(rootIdx+1, end, nums);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return helper(0,nums.size()-1,nums);
    }
};