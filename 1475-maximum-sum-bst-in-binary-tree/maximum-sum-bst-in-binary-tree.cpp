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
    int maxSum = 0;
    struct INFO{
        bool isBST;
        int sum;
        int minVal; 
        int maxVal;
    };

    INFO helper(TreeNode* root){
        if(!root){
            return {true,0,INT_MAX, INT_MIN};
        }

        INFO left = helper(root->left);
        INFO right = helper(root->right);

        // if BST 
        if(left.isBST && right.isBST && left.maxVal < root->val && right.minVal > root->val){

            INFO curr;
            curr.isBST = true;
            curr.sum = root->val + left.sum +right.sum;
            curr.minVal = min(left.minVal, root->val);
            curr.maxVal = max(right.maxVal, root->val);

            maxSum = max(maxSum, curr.sum);
            return curr;
        }
        // if not BST
        return {false, 0, 0, 0}; // since left.isBST and right.isBST get checked first other values doesn't matter.
    }

    int maxSumBST(TreeNode* root) {
        
        helper(root);
        return maxSum;
    }
};