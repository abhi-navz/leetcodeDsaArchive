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
    int maxDepth(TreeNode* root) {

        // the intuiton is that the height of maximum depth of a bianry tree will be [1 + max of height of left subtree and right subtree]

        // base case: if the root is nullptr , the height will be zero.
        if(root == nullptr){
            return 0;
        }
        return 1+ max(maxDepth(root->left), maxDepth(root->right));
        
    }
};
