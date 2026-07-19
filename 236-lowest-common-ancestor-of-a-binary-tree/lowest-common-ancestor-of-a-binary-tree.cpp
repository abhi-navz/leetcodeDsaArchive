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
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent){
        if(!root) return;

        if(root->left){
            parent[root->left] = root;
            findParent(root->left, parent);
        }
        if(root->right){
            parent[root->right] = root;
            findParent(root->right, parent);
        }


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        unordered_map<TreeNode*, TreeNode*>parent;
        parent[root] = root;

        findParent(root, parent);

        unordered_set<TreeNode*>visited; // to track visisted
        // visiting from p to root first an storing in set.

        visited.insert(p);
        TreeNode* node = p;
        while(parent[node] != node){
            node = parent[node];
            visited.insert(node);
        }

        // visit from q to root and if there's already a node in the set, it's lca.

        node = q;

        while(node != parent[node]){
            if(visited.find(node) == visited.end()){
                node = parent[node];
            }else{
                return node;
            }
        }

        return root;


    }
};