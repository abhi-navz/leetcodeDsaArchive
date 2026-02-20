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
        if(!root) return data;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                data += "#,";
                continue;
            }

            data += to_string(curr->val);
            data += ","; // better than doing just + "," in above line, as + involves coyping data + coyong "," to a temporray string then assigning back to data : not efficient while += works same as append;

            q.push(curr->left);
            q.push(curr->right);
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.size() == 0) return nullptr;

        stringstream ss( data);
        string token; 
        getline(ss,token,','); // token will store the data before the delimeter

        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            TreeNode* curr = q.front();
            q.pop();

            // left child 
            if(!getline(ss,token,',')) break;
            if(token != "#"){
                TreeNode* leftNode = new TreeNode(stoi(token));
                curr->left = leftNode;
                q.push(leftNode);
            }

            // right child
            if(!getline(ss,token,','))break;
            if(token != "#"){
                TreeNode* rightNode = new TreeNode(stoi(token));
                curr->right = rightNode;
                q.push(rightNode);
            }


        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
