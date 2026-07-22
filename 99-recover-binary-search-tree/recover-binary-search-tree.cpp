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

    TreeNode *prev, *first, *second;
    
    void inorder(TreeNode* curr){
        if(!curr)return;
        inorder(curr->left);
        if(prev && prev->val > curr->val){
            if(!first)
                first = prev;
            second = curr;    
        }
        prev = curr;
        inorder(curr->right);
    }

public:
    void recoverTree(TreeNode* root) {
        prev = nullptr;
        first = nullptr;
        second = nullptr;
        inorder(root);
        swap(first->val, second->val);
    }
};