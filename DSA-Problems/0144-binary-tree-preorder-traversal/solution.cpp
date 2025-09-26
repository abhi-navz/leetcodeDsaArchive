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
    vector<int> preorderTraversal(TreeNode* root) {

        // Iterative apporach for preorder Traversal

        vector<int> ans;
        if(root == NULL){
            return ans;

        }
        stack <TreeNode*> st;
        st.push(root);

        while(!st.empty() ){
            root = st.top();
            st.pop();
            ans.push_back(root->val);

            // pushing the right child into stack first
            if(root->right != nullptr){
                st.push(root->right);
            }
            // pushign the left child into stack now
            if(root->left != nullptr){
                st.push(root->left);
            }


        }

        return ans;
       

        return ans;

        
    }
};
