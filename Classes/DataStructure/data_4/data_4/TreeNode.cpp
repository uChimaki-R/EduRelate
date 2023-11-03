#include "TreeNode.h"

// 创建新节点
TreeNode* createNode(Student& data) {
	TreeNode* newNode = new TreeNode();
	if (!newNode) {
		cout << "Memory error";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// 插入节点
TreeNode* insertNode(TreeNode* root, Student& data) {
	if (root == NULL) {
		root = createNode(data);
		return root;
	}
	if (data.id < root->data.id) {
		root->left = insertNode(root->left, data);
	}
	else {
		root->right = insertNode(root->right, data);
	}
	return root;
}

// 前序遍历递归算法
void preOrderTraversalRecursive(TreeNode* root) {
	if (root == NULL) return;
	root->data.show_info();
	preOrderTraversalRecursive(root->left);
	preOrderTraversalRecursive(root->right);
}


TreeNode* searchNode(TreeNode* root, string id) {
	if (root == NULL || root->data.id == id) {
		return root;
	}
	if (id < root->data.id) {
		return searchNode(root->left, id);
	}
	else {
		return searchNode(root->right, id);
	}
}

// 删除数据
TreeNode* deleteNode(TreeNode* root, string& id) {
	if (root == NULL) return root;
	if (root->data.id == id) {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		else if (root->left == NULL) {
			TreeNode* tmp = root->right;
			delete root;
			return tmp;
		}
		else if (root->right == NULL) {
			TreeNode* tmp = root->left;
			delete root;
			return tmp;
		}
		else {
			TreeNode* cur = root->right;
			while (cur->left != NULL) {
				cur = cur->left;
			}
			cur->left = root->left;
			TreeNode* tmp = root;
			root = root->right;
			delete tmp;
			return root;
		}
	}
	if (root->data.id > id)
		root->left = deleteNode(root->left, id);
	if (root->data.id < id)
		root->right = deleteNode(root->right, id);
	return root;
}