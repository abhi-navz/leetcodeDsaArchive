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
    class BSTIterator {
        stack<TreeNode*>st;
    public:
        BSTIterator(TreeNode* root) {
            pushAllLeft(root);
        }

        void pushAllLeft(TreeNode* node){
            while(node){
                st.push(node);
                node = node->left;
            }
        }
        
        int next() {
            
            TreeNode *curr = st.top();
            st.pop();
            TreeNode *root = curr->right;
            pushAllLeft(root);
            return curr->val;
        }
        
        bool hasNext() {
            return (!st.empty());
        }
    };

    /**
    * Your BSTIterator object will be instantiated and called as such:
    * BSTIterator* obj = new BSTIterator(root);
    * int param_1 = obj->next();
    * bool param_2 = obj->hasNext();
    */