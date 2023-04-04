#include <iostream>
#include <vector>

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

int main() {

	cin.get();
}