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

    TreeNode* findMin(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        // checking if the root is null
        if(root == nullptr) return nullptr;

        // searching for the node
        if(key< root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            // the node is found

            // case 01: no children
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }

            // case 02: one children 
            else if(root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
             else if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // case 03: if the node has two children 

            // we'll find the inorder succesor, the smallest elment (temp) in the right subtree and then copy the data of temp to root and then we will delete the inorder successor from the tree as it'll be a duplicate

            TreeNode* temp = findMin(root->right);

            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        
    return root;
    }
};
