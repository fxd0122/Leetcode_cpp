// 3-18：有bug 没有delete 要删除的节点 
// 虚拟头节点也应该delete!
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* vhead = new ListNode();
        vhead->next = head;
        ListNode* first = head, *second = vhead;
        int count = 0;
        while(first!=nullptr){
            first = first->next;
            count++;
            if(count > n){
                second = second->next;
            }
        }
        second->next = second->next->next;
        //delete second->next;  // 删除了就报错==!  
        return vhead->next;
    }
};