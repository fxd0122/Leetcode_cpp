/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        ListNode* temp = head;
        while(temp != nullptr){
            s.push(temp->val);
            temp = temp->next;
        }
        while(!s.empty()){
            int top = s.top();
            s.pop();
            ans.push_back(top);
        }
        return ans;
    }
};