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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp != nullptr){
                q.pop();
                if(q.front() == nullptr){
                    ans.push_back(temp->val);
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            else{
                q.push(nullptr);
                q.pop();
                if(q.front() == nullptr) break;
            }
        }
        return ans;
    }
};