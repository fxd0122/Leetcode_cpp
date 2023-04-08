/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        stack<Node*> s;
        if(root != nullptr) s.push(root);
        while(!s.empty()){
            Node* temp = s.top();
            if(temp != nullptr){
                s.pop();
                int size = (temp->children).size();
                for(int i=size-1; i>=0; i--){
                    s.push((temp->children)[i]);
                }
                s.push(temp);
                s.push(nullptr);
            }
            else{
                s.pop();
                temp = s.top();
                s.pop();
                ans.push_back(temp->val);
            }
        } 
        return ans;
    }
};