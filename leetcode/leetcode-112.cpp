bool recur(TreeNode* cur, int curSum, int targetSum){
        if(!cur) return false;
        if(!cur->left && !cur->right){
            if(curSum+cur->val == targetSum){
                return true;
            }
            else return false;
        }
        return recur(cur->left, curSum+cur->val, targetSum) || recur(cur->right, curSum+cur->val, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return recur(root, 0, targetSum);
    }
};