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
    ListNode* swapPairs(ListNode* head) {
        ListNode* vhead = new ListNode();
        vhead->next = head;
        ListNode* odd, *even;
        even = vhead->next;
        ListNode* pre = vhead;
        while(even!=nullptr){
            odd = even->next;
            if(odd == nullptr)
                break;
            ListNode* temp = odd->next;
            // exchange
            pre->next = odd;
            even->next = odd->next;
            odd->next = even;
            pre = even;
            even = temp;
        }
        return vhead->next;
    }
};