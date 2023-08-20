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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        vector<ListNode*> v;
        while(temp!=nullptr){
            if(find(v.begin(), v.end(), temp)!=v.end())
                return temp;
            v.push_back(temp);
            temp = temp->next;
        }
        return nullptr;
    }
};