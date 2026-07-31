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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        

        if(root==nullptr||root==p||root==q){
            return root;
        }
        TreeNode* left1=lowestCommonAncestor(root->left,p,q);
        TreeNode* right1=lowestCommonAncestor(root->right,p,q);

        if(left1!=nullptr&&right1!=nullptr){
            return root;
        }
        if(left1!=nullptr){
            return left1;
        }
        return right1;

    }
};
