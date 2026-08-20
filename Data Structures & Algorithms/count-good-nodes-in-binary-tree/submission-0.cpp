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
    int dfs(TreeNode* node, int val){
        if(node==nullptr){
            return 0;
        }
        int count=0;

        if(node->val>=val){
            count++;
        }
        val=max(val,node->val);

        count+=dfs(node->left,val);
        count+=dfs(node->right,val);

        return count;
        
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
