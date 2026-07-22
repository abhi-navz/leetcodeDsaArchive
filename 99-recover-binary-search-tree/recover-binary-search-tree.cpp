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
    vector<TreeNode*>arr;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
public:
    
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;

        inorder(root);

        for(int i =0; i<arr.size()-1; i++){
            if(arr[i]->val > arr[i+1]->val){
                if(!first)
                    first = arr[i];
                second = arr[i+1];    
            }
        }

        swap(first->val, second->val);
    }
};