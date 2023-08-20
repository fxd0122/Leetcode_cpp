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
    int rob(TreeNode* root) {
        vector<int> res = robtree(root);
        return max(res[0], res[1]);    
    }

    vector<int> robtree(TreeNode* root){
        if(!root) return {0, 0}; // 0:当前节点不偷 1:当前节点偷；
        vector<int> left = robtree(root->left);
        vector<int> right = robtree(root->right);
        // 不偷
        int val1 = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷
        int val2 = root->val + left[0] + right[0];
        return {val1, val2};
    }
};