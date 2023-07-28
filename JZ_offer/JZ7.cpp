/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param vinOrder int整型vector 
     * @return TreeNode类
     */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        // write code here
        return constructor(preOrder, vinOrder, 0, preOrder.size()-1, 0, vinOrder.size()-1);
    }

    TreeNode* constructor(vector<int>& preOrder, vector<int>& vinOrder,
                          int pbegin, int pend, int vbegin, int vend){
        if(vbegin > vend) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preOrder[pbegin]);
        int index = vbegin;
        for(index; index <= vend; index++){
            if(vinOrder[index] == preOrder[pbegin]){
                break;
            }
        }
        int numLeftNode = index - vbegin;
        int numRightNode = vend - index;
        root->left = constructor(preOrder, vinOrder, pbegin+1, pbegin+numLeftNode, vbegin, index-1);
        root->right = constructor(preOrder, vinOrder, pbegin+numLeftNode+1, pend, index+1, vend);
        return root;
    }
};