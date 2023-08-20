class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode() {next = nullptr;}
        ListNode(int x) {val = x; next = nullptr;}
    };
    ListNode* vhead;
    int size;
    MyLinkedList() {
        vhead = new ListNode();
        size = 0;
    }
    
    int get(int index) {
        if(index < size){
            ListNode* cur = vhead;
            for(int i=0; i<=index; i++)
                cur = cur->next;
            return cur->val;
        }
        else{
            return -1;
        }
    }
    
    void addAtHead(int val) {
        ListNode* temp = new ListNode(val);
        temp->next = vhead->next;
        vhead->next = temp;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = vhead;
        while(cur->next!=nullptr){
            cur = cur->next;
        }
        ListNode* temp = new ListNode(val);
        cur->next = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index==size){
            addAtTail(val);
        }
        else if(index<size){
            ListNode* cur = vhead, *pre = vhead;
            for(int i=0; i<=index; i++){
                pre = cur;
                cur = cur->next;
            }
            ListNode* temp = new ListNode(val);
            pre->next = temp;
            temp->next = cur;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < size){
            ListNode* cur = vhead, *pre = vhead;
            for(int i=0; i<=index; i++){
                pre = cur;
                cur = cur->next;
            }
            pre->next = cur->next;
            delete cur;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */