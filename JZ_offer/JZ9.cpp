class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty() && stack1.empty()){
            throw ;
        }
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int temp = stack2.top();
        stack2.pop();
        return temp;
    }

private:
    stack<int> stack1; // 入对栈
    stack<int> stack2; // 出对栈
};