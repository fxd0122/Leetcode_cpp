#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

void PreTraversal(vector<int>& vec, TreeNode* cur) {
	if (cur == nullptr) return;
	vec.push_back(cur->val);
	PreTraversal(vec, cur->left);
	PreTraversal(vec, cur->right);
}

void MidTraversal(vector<int>& vec, TreeNode* cur) {
	if (cur == nullptr) return;
	MidTraversal(vec, cur->left);
	vec.push_back(cur->val);
	MidTraversal(vec, cur->right);
}

void PostTraversal(vector<int> vec, TreeNode* cur) {
	if (cur == nullptr) return;
	PostTraversal(vec, cur->left);
	PostTraversal(vec, cur->right);
	vec.push_back(cur->val);
}

vector<int> BinTreeTraversal(TreeNode* root) {
	vector<int> pre_res, mid_res, post_res;
	// preorder
	PreTraversal(pre_res, root);
	// midorder
	MidTraversal(mid_res, root);
	//postorder
	PostTraversal(post_res, root);

	return pre_res;
}

vector<int> noneRecPreTraversal(TreeNode* root){
	stack<TreeNode*> s;
	vector<int> ans;
	if(root == nullptr) return ans;
	s.push(root);
	while(!s.empty()){
		TreeNode* temp = s.top();
		ans.push_back(temp->val);
		s.pop();
		if (temp->right) s.push(temp->right);
		if (temp->left) s.push(temp->left);
	}
	return ans;
}

vector<int> noneRecMidTraversal(TreeNode* root){
	stack<TreeNode*> s;
	vector<int> ans;
	if(root == nullptr) return ans;
	TreeNode* cur = root;
	while(cur != nullptr || !s.empty()){
		if(cur != nullptr){
			s.push(cur);
			cur = cur->left;
		}
		else{
			cur = s.top();
			s.pop();
			ans.push_back(cur->val);
			cur = cur->right;
		}
	}
	return ans;
}

vector<int> noneRecPostTraversal(TreeNode* root){
	stack<TreeNode*> s;
	vector<int> ans;
	if(root == nullptr) return ans;
	s.push(root);
	while(!s.empty()){
		TreeNode* temp = s.top();
		ans.push_back(temp->val);
		s.pop();
		if (temp->left) s.push(temp->left);
		if (temp->right) s.push(temp->right);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

vector<int> uniformTraversal(TreeNode* root){
	stack<TreeNode*> s;
	vector<int> ans;
	if(root != nullptr) s.push(root);
	while(!s.empty()){
		TreeNode* temp = s.top(); //访问节点
		if(temp != nullptr){
			s.pop();

			// 前序遍历
			// if(temp->right) s.push(temp->right);
			// if(temp->left) s.push(temp->left);
			// s.push(temp); // push需要处理的节点
			// s.push(nullptr); // push标志节点

			// 中序遍历
			if(temp->right) s.push(temp->right);
			s.push(temp);
			s.push(nullptr);
			if(temp->left) s.push(temp->left);

			// 后序遍历
			// s.push(temp); // push需要处理的节点
			// s.push(nullptr); // push标志节点
			// if(temp->right) s.push(temp->right);
			// if(temp->left) s.push(temp->left);
		}
		else{
			s.pop();
			temp = s.top();
			s.pop();
			ans.push_back(temp->val);
		}
	}
}

int main() {

	cin.get();
}