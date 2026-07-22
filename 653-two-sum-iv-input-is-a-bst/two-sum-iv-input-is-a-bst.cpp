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

    stack<TreeNode*> st1, st2;

    void pushLeft(TreeNode* root) {
        while (root) {
            st1.push(root);
            root = root->left;
        }
    }

    void pushRight(TreeNode* root) {
        while (root) {
            st2.push(root);
            root = root->right;
        }
    }

    bool helper(int k) {

        while (!st1.empty() && !st2.empty()) {
            // base case
            if (st1.top() == st2.top()) {
                return false;
            }
            int sum = st1.top()->val + st2.top()->val;

            if (sum == k)
                return true;
            else if (sum < k) {
                TreeNode* curr = st1.top();
                st1.pop();
                pushLeft(curr->right);
            } else {
                TreeNode* curr = st2.top();
                st2.pop();
                pushRight(curr->left);
            }
        }
        return false;
    }

public:
    bool findTarget(TreeNode* root, int k) {

        pushLeft(root);
        pushRight(root);

        return helper(k);
    }
};