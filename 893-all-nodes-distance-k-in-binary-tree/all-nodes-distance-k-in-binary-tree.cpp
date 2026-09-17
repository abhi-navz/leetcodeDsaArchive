/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){

        if(!root) return;
        if(root->left){
            parent[root->left] = root;
            markParent(root->left, parent);
        }

        if(root->right){
            parent[root->right] = root;
            markParent(root->right, parent);
        }

    }


    void getNodes(TreeNode* source, TreeNode* last, vector<int>&ans, int k, unordered_map<TreeNode*, TreeNode*>&parent){


        if(k ==0){
            ans.push_back(source->val);
            return;
        }

        if(source->left && source->left != last){
            getNodes(source->left, source, ans, k-1, parent);
        }

        if(source->right && source->right != last){
            getNodes(source->right, source,ans, k-1, parent);
        }

        if(parent.count(source) && parent[source] != last){
            getNodes(parent[source], source, ans, k-1, parent);
        }


    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root) return  ans;

        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);

        getNodes(target,nullptr,ans,k, parent);
        return ans;




    }
};