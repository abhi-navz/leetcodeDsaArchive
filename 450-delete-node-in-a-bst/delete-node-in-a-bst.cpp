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
    TreeNode *inSucc(TreeNode* root){
        TreeNode *curr = root;
        while(curr->left){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }else if(key>root->val){
            root->right = deleteNode(root->right, key);
        }else{
            // key is found
            //case 1: leaf node
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            //case 2: one child
            else if((root->left && !root->right ) || (!root->left && root->right)){

                if(root->left){
                    TreeNode* child = root->left;
                    delete root;
                    return child;
                }
                else{
                    TreeNode *child = root->right;
                    delete root;
                    return child;
                }
            }
            // two child
            else{
                TreeNode *succ = inSucc(root->right);
                root->val =succ->val;
                root->right = deleteNode(root->right, succ->val);
                return root;
            }
        }
        return root;
    }
};