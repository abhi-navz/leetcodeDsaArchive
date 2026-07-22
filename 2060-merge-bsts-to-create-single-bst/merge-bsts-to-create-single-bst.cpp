/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, TreeNode*> roots;
    unordered_set<int>leaves;

    TreeNode* dfs(TreeNode* node) {
        if (!node)
            return nullptr;
        if (!node->left && !node->right) {
            int leaf = node->val;
            if (roots.count(leaf)) {
                node = roots[leaf];
                roots.erase(leaf);
            }
        }
        node->left = dfs(node->left);
        node->right = dfs(node->right);

        return node;
    }

    bool isBST(TreeNode* root, long long min, long long max) {
        if (!root)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return isBST(root->left, min, root->val) &&
               isBST(root->right, root->val, max);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {

        // storing roots and leaves in map for constant lookup
        for (TreeNode* r : trees) {
            roots[r->val] = r;
            if(r->left){
                leaves.insert(r->left->val);
            }
            if(r->right){
                leaves.insert(r->right->val);
            }
        }

        // finding the parent root
        TreeNode* root = nullptr;
        for(TreeNode *tree : trees){
            if(!leaves.count(tree->val)){
                if(root)
                    return nullptr;
                root = tree;
                
            }
        }
        if(!root) return nullptr;
        roots.erase(root->val);

        // attaching trees
        root = dfs(root);

        if (!roots.empty())
            return nullptr;

        // validating if the tree is BST
        if (isBST(root, LLONG_MIN, LLONG_MAX))
            return root;
        return nullptr;
    }
};