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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==nullptr){
            return "";
        }

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node==nullptr){
                s+="#,";
                continue;
            }
            s+=to_string(node->val)+",";

            q.push(node->left);
            q.push(node->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data==""){
            return nullptr;
        }

        stringstream ss(data);
        string val;

        getline(ss,val,',');
        TreeNode* root=new TreeNode(stoi(val));

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            getline(ss,val,',');
            if(val!="#"){
                node->left=new TreeNode(stoi(val));
                q.push(node->left);
            }
            getline(ss,val,',');
            if(val!="#"){
                node->right=new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};
