class MyQueue {
public:
    MyQueue() {

    }  
    stack<int> A;
    stack<int> B;
    void push(int x) {
        A.push(x);
    }
    
    int pop() {
        if(!B.empty()){
            int temp = B.top();
            B.pop();
            return temp;
        }
        else{
            while(!A.empty()){
                int temp = A.top();
                B.push(temp);
                A.pop();
            }
            int temp = B.top();
            B.pop();
            return temp;
        }
    }
    
    int peek() {
        if(!B.empty()){
            return B.top();
        }
        else{
            while(!A.empty()){
                int temp = A.top();
                B.push(temp);
                A.pop();
            }
            return B.top();
        }
    }
    
    bool empty() {
        if(A.empty() && B.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */