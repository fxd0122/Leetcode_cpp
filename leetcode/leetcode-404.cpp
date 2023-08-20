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
    int recur(TreeNode* cur){
        int left_sum = 0;
        int right_sum = 0;
        if(cur->left){
            TreeNode* left_child = cur->left;
            if(left_child->left == nullptr && left_child->right == nullptr){
                left_sum += left_child->val;
            }
            else{
                left_sum+=recur(left_child);
            }
        }
        if(cur->right){
            right_sum += recur(cur->right);
        }
        return left_sum+right_sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return recur(root);
    }
};