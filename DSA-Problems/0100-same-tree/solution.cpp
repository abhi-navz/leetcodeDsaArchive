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


    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both are root are null return true.
        if(!p && !q) return true;

        // if one root is null but not null
        if((!p && q) || (p&&!q)) return false;

        // if none is null
        return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right,q->right));
        
      



        
    }
};
