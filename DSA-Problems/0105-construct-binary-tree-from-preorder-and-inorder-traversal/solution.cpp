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
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd,
                     vector<int>& inorder, int inStart, int inEnd,
                     unordered_map<int, int>& inMap) {

        // base case
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRootPos = inMap[root->val];  // log n ; 

        int numsLeft = inRootPos - inStart;

        root->left = helper(preorder, preStart + 1, preStart + numsLeft,
                            inorder, inStart, inRootPos - 1, inMap);

        root->right = helper(preorder, preStart + numsLeft + 1, preEnd, inorder,
                             inRootPos + 1, inEnd, inMap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i; 
        }

        TreeNode* root = helper(preorder, 0, preorder.size() - 1, inorder, 0,
                                 inorder.size() - 1, inMap);
        return root;
    }
};
