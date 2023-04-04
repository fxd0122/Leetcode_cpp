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
    void Traversal(vector<int>& vec, TreeNode* cur){
        if(cur == nullptr) return ;
        vec.push_back(cur->val);
        Traversal(vec, cur->left);
        Traversal(vec, cur->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(res, root);
        return res;
    }
};

class Solution {
public:
    void Traversal(vector<int>& vec, TreeNode* cur){
        if(cur == nullptr) return ;
        Traversal(vec, cur->left);
        Traversal(vec, cur->right);
        vec.push_back(cur->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(res, root);
        return res;
    }
};

class Solution {
public:
    void Traversal(vector<int>& vec, TreeNode* cur){
        if(cur == nullptr) return;
        Traversal(vec, cur->left);
        vec.push_back(cur->val);
        Traversal(vec, cur->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Traversal(res, root);
        return res;
    }
};