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
    TreeNode* recur(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size()==0 || postorder.size()==0) return nullptr;
        int root_val = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode(root_val);
        // root->val = root_val;
        int mid_index = 0;
        for(int i=0; i<inorder.size(); i++){
            if(inorder[i] == root_val){
                mid_index = i;
                break;
            }
        }
        vector<int> left_inorder(inorder.begin(), inorder.begin()+mid_index);
        vector<int> right_inorder(inorder.begin()+mid_index+1, inorder.end());
        vector<int> left_postorder(postorder.begin(), postorder.begin()+mid_index);
        vector<int> right_postorder(postorder.begin()+mid_index, postorder.end()-1); 
        root->left = recur(left_inorder, left_postorder);
        root->right = recur(right_inorder, right_postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0) return nullptr;
        return recur(inorder, postorder);
    }
};