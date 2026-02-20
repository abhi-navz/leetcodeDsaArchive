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
    TreeNode* helper(vector<int>& postorder, int postStart, int postEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& inMap) {

        // base case
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int rootPos = inMap[root->val];

        int numsLeft = rootPos - inStart;

        root->left = helper(postorder, postStart, postStart + numsLeft - 1,
                            inorder, inStart, rootPos - 1, inMap);

        root->right = helper(postorder, postStart + numsLeft, postEnd - 1,
                             inorder, rootPos + 1, inEnd,inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map < int, int> inMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = helper(postorder, 0, postorder.size() - 1, inorder, 0,
                                inorder.size() - 1, inMap);
        return root;
    }
};
