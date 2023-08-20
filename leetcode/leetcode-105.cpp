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
    TreeNode* recur(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size()==0 || inorder.size()==0) return nullptr;
        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);
        // root->val = root_val;
        int mid_index = 0;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == root_val){
                mid_index = i;
                break;
            }
        }
        vector<int> left_preorder(preorder.begin()+1, preorder.begin()+mid_index+1);
        vector<int> right_preorder(preorder.begin()+mid_index+1, preorder.end());
        vector<int> left_inorder(inorder.begin(), inorder.begin()+mid_index);
        vector<int> right_inorder(inorder.begin()+mid_index+1, inorder.end()); 
        root->left = recur(left_preorder, left_inorder);
        root->right = recur(right_preorder, right_inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0||inorder.size()==0) return nullptr;
        return recur(preorder, inorder);
    }
};