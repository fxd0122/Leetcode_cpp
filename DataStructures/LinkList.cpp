#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node(int val):value(val), next(nullptr){}
};

void addHead(Node* vhead, int val){
    Node* temp = vhead->next;
    vhead->next = new Node(val);
    vhead->next->next = temp;
}

void printLinkList(Node* vhead){
    if(vhead->next == nullptr){
        cout << "Link list is empty\n";
    }else{
        Node* temp = vhead->next;
        while(temp){
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << "\n";   
    }
}

void deleteNode(Node* vhead, int index){
    Node* cur = vhead;
    Node* pre = vhead;
    while(index>0){
        pre = cur;
        cur = cur->next;
        if(cur == nullptr){
            cout << "delete fail\n";
            return;
        }
        index--;
    }
    pre->next = cur->next;
    cur->next = nullptr;
    cout << "delete OK\n";
    delete cur;
}

void insertNode(Node* vhead, int index, int value){
    Node* cur = vhead;
    Node* pre = vhead;
    while(index>0){
        index--;
        pre = cur;
        cur = cur->next;
        if(cur == nullptr && index > 0){
            cout << "insert fail\n";
            return ;
        }
    }
    pre->next = new Node(value);
    pre->next->next = cur;
    cout << "insert OK\n";
}


void getValue(Node* vhead, int index){
    Node* cur = vhead;
    while(index > 0){
        cur = cur->next;
        if(cur == nullptr){
            cout << "get fail\n";
            return;
        }
        index--;
    }
    cout << cur->value << "\n";
}

int main(){
    int m, n;
    Node* vhead = new Node(0);
    vhead->next = nullptr;
    if(cin >> m){
        for(int i=0; i<m; i++){
            cin >> n;
            addHead(vhead, n);
        }
    }
    int numOps;
    if(cin >>numOps){
        for(int i=0; i<numOps; i++){
            string s;
            cin >> s;
            if(s == "show"){
                printLinkList(vhead);
            }else if(s == "delete"){
                int index;
                cin >> index;
                deleteNode(vhead, index);
            }else if(s == "insert"){
                int index, value;
                cin >> index >> value;
                insertNode(vhead, index, value);
            }else if(s == "get"){
                int index;
                cin >> index;
                getValue(vhead, index);
            }
        }
    }
    return 0;
}