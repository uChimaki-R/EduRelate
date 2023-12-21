#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode(int x) : val(x) {}
};

class BST {
public:
	// 查找元素，如果找不到则插入到二叉搜索树中
	void searchOrInsert(int val) {
		TreeNode* node = find(root, val);
		if (node == NULL) {
			node = new TreeNode(val);
			insert(root, node);
			cout << "<Insert Node> val: " << node->val << endl;
		}
		else {
			cout << "<Existing Node> val: " << node->val << endl;
		}
	}

private:
	TreeNode* root = nullptr;

	// 查找元素
	TreeNode* find(TreeNode* node, int val) {
		if (node == NULL || node->val == val) {
			return node;
		}
		else if (node->val > val) {
			return find(node->left, val);
		}
		else {
			return find(node->right, val);
		}
	}

	// 插入元素
	void insert(TreeNode*& node, TreeNode* newNode) {
		if (node == NULL) {
			node = newNode;
		}
		else if (newNode->val < node->val) {
			insert(node->left, newNode);
		}
		else {
			insert(node->right, newNode);
		}
	}
};

int main() {
	BST bst;

	/*bst.searchOrInsert(1);
	bst.searchOrInsert(2);
	bst.searchOrInsert(3);
	bst.searchOrInsert(3);
	bst.searchOrInsert(2);
	bst.searchOrInsert(7);
	bst.searchOrInsert(8);
	bst.searchOrInsert(1);*/

	while (true) {
		int val;
		cout << "searchOrInsert(0 to exit): ";
		cin >> val;
		if (!val)break;
		bst.searchOrInsert(val);
	}

	return 0;
}
