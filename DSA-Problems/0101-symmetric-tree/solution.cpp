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
public:
    bool isSymmetric(TreeNode* root) {

        if (!root)
            return true;
        queue<pair<TreeNode*, TreeNode*>> q;

        q.push({root->left, root->right});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* a = it.first;
            TreeNode* b = it.second;

            if ((!a && b) || (a && !b))
                return false;

            if (!a && !b)
                continue;

            if (a->val != b->val)
                return false;

            q.push({a->left, b->right});

            q.push({a->right, b->left});
        }

        return true;
    }
};
