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
    TreeNode *prev = nullptr;
    void flatten(TreeNode* root) {
        if(!root) return ;


        // we'll process in rev pre order root, left, root.
        // we'll first flatten right subteree and then left subtree and then set root->right = prev. which will be the root of prvious flattened subtrees.

        flatten(root->right);
        flatten(root->left);

        root->left = nullptr;
        root->right = prev; // as next;
        prev = root;
    }
};