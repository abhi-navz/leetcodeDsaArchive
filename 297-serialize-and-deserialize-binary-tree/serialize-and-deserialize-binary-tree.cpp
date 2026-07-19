/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        if(!root)return data;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode *curr = q.front();
            q.pop();
            if(curr == nullptr){
                data += "#,";
                continue;
            }else{
                data += to_string(curr->val);
                data += ",";
            }

            q.push(curr->left);
            q.push(curr->right);
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(!data.size())return nullptr;

        stringstream ss(data);
        string token;

        getline(ss, token,',');
        TreeNode *root = new TreeNode(stoi(token));
        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            // left child 
            if(!getline(ss, token, ','))break;
            if(token != "#"){
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }

            //right child
            if(!getline(ss,token, ','))break;
            if(token != "#"){
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }

        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));