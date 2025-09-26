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
    int minDepth(TreeNode* root) {
        
        // base case: 
        if(root == nullptr){
            return 0;
        }

        // if the left of root is empty , we'll take minimum Depth of the right subtree

        if(root->left == nullptr){
            return 1+ minDepth(root->right);
        }
        // similairy if the right of root is empty , we'll take minimum Depth of the left subtree
        else if( root->right == nullptr){
            return 1+minDepth(root->left);
        }

        else{
            return 1+min(minDepth(root->left), minDepth(root->right));
        }
    }
};
