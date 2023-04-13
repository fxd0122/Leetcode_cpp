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
    bool recur(TreeNode* root, long cur_min, long cur_max){
        if(!root) return true;
        // bool ans = false;
        // if(root->left){
        //     if(root->val>root->left->val && root->val<cur_max) ans = true;
        //     else ans = false;
        // }
        // if(root->right){
        //     if(root->val<root->right->val && root->val>cur_min) ans = ans && true;
        //     else ans = false;
        // }
        // if(root->val>cur_min&&root->val<cur_max) ans = true;
        return root->val>cur_min&&root->val<cur_max&&recur(root->left, cur_min, long(root->val))&&recur(root->right, long(root->val), cur_max);
    }

    bool isValidBST(TreeNode* root) {
        return recur(root, long(INT_MIN)-1, long(INT_MAX)+1);
    }
};