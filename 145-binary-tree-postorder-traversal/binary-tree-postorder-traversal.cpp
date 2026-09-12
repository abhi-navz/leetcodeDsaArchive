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

        // using one stack, we need one extra pointer in this case. lastVisited; 
        
        vector<int>ans;
        if(!root) return ans;

        TreeNode* lastVis = nullptr;
        TreeNode* curr = root;
        stack<TreeNode*>st;

        

        while(!st.empty() || curr != nullptr ){

            if(curr){
                // go left as possible
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* top = st.top();
                // if right subtree exist and not visited 

                if(top->right && top->right != lastVis){
                    curr = top->right;
                }else{
                    // both left and right subtree are done
                    ans.push_back(top->val);
                    lastVis = top;
                    st.pop();
                }
            }
        }

        return ans;
    }
};