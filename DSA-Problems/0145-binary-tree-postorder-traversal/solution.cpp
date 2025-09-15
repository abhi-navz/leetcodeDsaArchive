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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        
        vector<int>ans;
        // inserting the left nodes from left subtrees
        vector<int>left = postorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        

        // inserting the right subtree
        vector<int> right = postorderTraversal(root->right);
        ans.insert(ans.end(),right.begin(), right.end());

        // pushing the root
        ans.push_back(root->val);
        

         return ans;
        
    }
};
