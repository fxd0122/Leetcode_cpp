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
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> s;
        s.push(root);
        int sum = 0;
        while(!s.empty()){
            TreeNode* temp = s.top();
            if(temp){
                s.pop();
                if(temp->left) s.push(temp->left);
                s.push(temp);
                s.push(nullptr);
                if(temp->right) s.push(temp->right);
            }
            else{
                s.pop();
                temp = s.top();
                s.pop();
                sum += temp->val;
                temp->val = sum;
            }
        }
        return root;
    }
};