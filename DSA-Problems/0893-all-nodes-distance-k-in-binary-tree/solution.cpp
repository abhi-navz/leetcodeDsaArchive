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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&trackParent, TreeNode* target){

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr->left){
                q.push(curr->left);
                trackParent[curr->left] = curr;
            }
            if(curr->right){
                q.push(curr->right);
                trackParent[curr->right] = curr;
            }
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // marking parents
        unordered_map<TreeNode*,TreeNode*>trackParent; // node->parent
        markParent(root,trackParent,target);

        unordered_map<TreeNode*, bool>visited;  // to keep track of visited nodes
        queue<TreeNode*>q;
        int currLvl =0;

        q.push(target);
        visited[target] = true;


        while(!q.empty()){
            int size = q.size();
            if(currLvl++ == k) break;

            for(int i =0; i<size; i++){
                TreeNode* curr = q.front(); q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;

                }
                if(trackParent[curr] && !visited[trackParent[curr]]){
                    q.push(trackParent[curr]);
                    visited[trackParent[curr]] = true;
                }
            }

        }

        vector<int>res;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            res.push_back(node->val);
        }

        return res;

        

        
    }
};
