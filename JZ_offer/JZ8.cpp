/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
#include <iterator>
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode == nullptr){
            return nullptr;
        } 
        if(pNode->right){
            TreeLinkNode* temp = pNode->right;
            while(temp->left){
                temp = temp->left;
            }
            return temp;
        }
        else{
            TreeLinkNode* temp = pNode;
            while(temp->next && temp->next->right == temp){
                temp = temp->next;
            }
            return temp->next;
        }
    }
};
