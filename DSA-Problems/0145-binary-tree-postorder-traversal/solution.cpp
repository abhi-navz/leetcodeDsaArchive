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

    // iterative apporach for postOrder traversal using two stacks.
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> s1, s2;
        // pushing the root in s1 first.
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* node = s1.top();
            // poping and pushing the root into 2
            s1.pop();
            s2.push(node);

            // pushing the child of root into s1

            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }

        while (!s2.empty()) {
            // poping the elemetns from s2 and storing it in result
            result.push_back(s2.top()->val);
            s2.pop();
        }

        return result;
        
    }
};
