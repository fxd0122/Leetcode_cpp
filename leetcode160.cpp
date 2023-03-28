/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* temp = headA;
        while(temp!=nullptr){
            lenA++;
            temp = temp->next;
        }
        temp = headB;
        while(temp!=nullptr){
            lenB++;
            temp = temp->next;
        }
        ListNode* searchHeadA = headA;
        ListNode* searchHeadB = headB;
        if(lenA>lenB){
            for(int i=0; i<lenA-lenB; i++)
                searchHeadA = searchHeadA->next;
        }
        else{
            for(int i=0; i<lenB-lenA; i++)
                searchHeadB = searchHeadB->next;
        }
        while(searchHeadA!=nullptr && searchHeadB!=nullptr){
            if(searchHeadA==searchHeadB)
                return searchHeadA;
            searchHeadA = searchHeadA->next;
            searchHeadB = searchHeadB->next;
        }
        return nullptr;
    }
};