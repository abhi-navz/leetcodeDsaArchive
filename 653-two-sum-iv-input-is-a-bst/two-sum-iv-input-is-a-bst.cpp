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
    void pushLeft(TreeNode* root,stack<TreeNode*>&st1){
        while(root){
            st1.push(root);
            root = root->left;
        }
    }

    void pushRight(TreeNode *root, stack<TreeNode*>&st2){
        while(root){
            st2.push(root);
            root = root->right;
        }
    }

    bool helper(TreeNode* root, int k ,stack<TreeNode*>&st1, stack<TreeNode*>&st2){

        while(!st1.empty() && !st2.empty()){
            // base case
            if(st1.top() == st2.top()){
                return false;
            }

            
            int top1 = st1.top()->val;
            int top2 = st2.top()->val;

            if(top1+top2 == k)return true;
            else if(top1+top2<k){
                TreeNode* curr = st1.top();
                st1.pop();
                pushLeft(curr->right,st1);
            }else{
                TreeNode* curr = st2.top();
                st2.pop();
                pushRight(curr->left, st2);
            }
        }
        return false;
         
    }
    bool findTarget(TreeNode* root, int k) {

        stack<TreeNode*>st1;
        stack<TreeNode*>st2;

        pushLeft(root,st1);
        pushRight(root,st2);

        return helper(root, k ,st1, st2);

    }
};