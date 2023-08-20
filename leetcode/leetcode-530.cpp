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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int last_val = INT_MAX;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* temp = s.top();
            if(temp){
                s.pop();
                if(temp->right) s.push(temp->right);
                s.push(temp);
                s.push(nullptr);
                if(temp->left) s.push(temp->left);
            }
            else{
                s.pop();
                temp = s.top();
                s.pop();
                if(last_val == INT_MAX) last_val = temp->val;
                else{
                    ans = min(abs(temp->val-last_val), ans);
                    last_val = temp->val;
                }
            }
        }
        return ans;
    }
};