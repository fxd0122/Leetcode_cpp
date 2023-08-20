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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        TreeNode* cur = root;
        TreeNode* parent = root;
        while(cur && cur->val != key){
            parent = cur;
            if(cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if(cur == nullptr) return root;
        if(cur->val < parent->val){
            if(!cur->left && !cur->right){
                parent->left = nullptr;
                // delete cur;
            }
            else{
                if(cur->right){
                    parent->left = cur->right;
                    TreeNode* temp = cur->right;
                    while(temp->left) temp = temp->left;
                    temp->left = cur->left;
                    // delete cur;
                }
                else parent->left = cur->left;
            }
            
        }
        else if(cur->val == parent->val){
            if(!cur->left && !cur->right){
                return nullptr;
                delete cur;
            }
            else{
                if(root->right){
                    // parent = root->right;
                    TreeNode* temp = cur->right;
                    cur = cur->right;
                    while(cur->left) cur = cur->left;
                    cur->left = parent->left;
                    root->left = nullptr;
                    root->right = nullptr;
                    root = temp;
                    // delete parent;
                }
                else root = root->left;
            }
        }
        else{
            if(!cur->left && !cur->right){
                parent->right = nullptr;
            }
            else{
                if(cur->right){
                    parent->right = cur->right;
                    TreeNode* temp = cur->right;
                    while(temp->left) temp = temp->left;
                    temp->left = cur->left;
                    // delete cur;
                }
                else parent->right = cur->left;
            }
            
        }
        return root;
    }
};