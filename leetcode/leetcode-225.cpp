class MyStack {
public:
    MyStack() {

    }
    queue<int> A;
    queue<int> B;
    void push(int x) {
        if(A.empty()){
            B.push(x);
        }
        else{
            A.push(x);
        }
    }
    
    int pop() {
        if(A.empty()){
            int size = B.size();
            size--;
            while(size){
                int temp = B.front();
                A.push(temp);
                B.pop();
                size--;
            }
            int s_top = B.front();
            B.pop();
            return s_top;
        }else{
            int size = A.size();
            size--;
            while(size){
                int temp = A.front();
                B.push(temp);
                A.pop();
                size--;
            }
            int s_top = A.front();
            A.pop();
            return s_top;
        }
    }
    
    int top() {
        if(A.empty()){
            return B.back();
        }
        else{
            return A.back();
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
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */