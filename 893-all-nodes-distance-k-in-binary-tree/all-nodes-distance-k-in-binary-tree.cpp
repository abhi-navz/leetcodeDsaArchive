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

    void findNodesAtK(TreeNode* source, TreeNode* last, int k,vector<int>&ans, unordered_map<TreeNode*, TreeNode*>&parent){

        if(k == 0){
            ans.push_back(source->val);
            return ;
        }

        if(source->left && source->left != last){
            findNodesAtK(source->left, source, k-1,ans,parent);
        }

        if(source->right && source->right != last){
            findNodesAtK(source->right, source, k-1,ans,parent);
        }
        if(parent[source] && parent[source] != last){
            findNodesAtK(parent[source], source, k-1, ans, parent);
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int>ans;
        unordered_map<TreeNode*, TreeNode*>parent;
        parent[root] = nullptr;
        markParent(root, parent);

        findNodesAtK(target, nullptr, k, ans,parent);
        return ans;



    }
};