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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(root == nullptr){
        //     TreeNode* node = new TreeNode(val);
        //     return node;
        // }
        // if(val>root->val) root->right = insertIntoBST(root->right, val);
        // if(val<root->val) root->left = insertIntoBST(root->left, val);
        // return root;
        if(root==nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* cur = root;
        TreeNode* parent = root;
        while(cur!=nullptr){
            parent = cur;
            if(val>cur->val) cur = cur->right;
            else cur = cur->left;
        }
        TreeNode* node = new TreeNode(val);
        if(val < parent->val) parent->left = node;
        else parent->right = node;
        return root;
    }
};