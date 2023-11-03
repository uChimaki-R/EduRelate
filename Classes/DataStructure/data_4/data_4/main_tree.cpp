//#include <iostream>
//#include <stack>
//using namespace std;
//
//struct TreeNode {
//	int data;
//	TreeNode* left;
//	TreeNode* right;
//};
//
//// 创建新节点
//TreeNode* createNode(int data) {
//	TreeNode* newNode = new TreeNode();
//	if (!newNode) {
//		cout << "Memory error";
//		return NULL;
//	}
//	newNode->data = data;
//	newNode->left = newNode->right = NULL;
//	return newNode;
//}
//
//// 插入节点
//TreeNode* insertNode(TreeNode* root, int data) {
//	if (root == NULL) {
//		root = createNode(data);
//		return root;
//	}
//
//	if (data < root->data) {
//		root->left = insertNode(root->left, data);
//	}
//	else {
//		root->right = insertNode(root->right, data);
//	}
//
//	return root;
//}
//
//// 前序遍历递归算法
//void preOrderTraversalRecursive(TreeNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	cout << root->data << " ";
//	preOrderTraversalRecursive(root->left);
//	preOrderTraversalRecursive(root->right);
//}
//
//// 前序遍历非递归算法
//void preOrderTraversalNonRecursive(TreeNode* root) {
//	if (root == NULL) {
//		return;
//	}
//
//	stack<TreeNode*> nodeStack;
//	nodeStack.push(root);
//
//	while (!nodeStack.empty()) {
//		TreeNode* currentNode = nodeStack.top();
//		nodeStack.pop();
//		cout << currentNode->data << " ";
//
//		if (currentNode->right) {
//			nodeStack.push(currentNode->right);
//		}
//		if (currentNode->left) {
//			nodeStack.push(currentNode->left);
//		}
//	}
//}
//
//// 中序遍历递归算法
//void inOrderTraversalRecursive(TreeNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	inOrderTraversalRecursive(root->left);
//	cout << root->data << " ";
//	inOrderTraversalRecursive(root->right);
//}
//
//// 中序遍历非递归算法
//void inOrderTraversalNonRecursive(TreeNode* root) {
//	if (root == NULL) {
//		return;
//	}
//
//	stack<TreeNode*> nodeStack;
//	TreeNode* currentNode = root;
//
//	while (currentNode != NULL || !nodeStack.empty()) {
//		while (currentNode != NULL) {
//			nodeStack.push(currentNode);
//			currentNode = currentNode->left;
//		}
//		currentNode = nodeStack.top();
//		nodeStack.pop();
//		cout << currentNode->data << " ";
//		currentNode = currentNode->right;
//	}
//}
//
//// 后序遍历递归算法
//void postOrderTraversalRecursive(TreeNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	postOrderTraversalRecursive(root->left);
//	postOrderTraversalRecursive(root->right);
//	cout << root->data << " ";
//}
//
//// 后序遍历非递归算法
//void postOrderTraversalNonRecursive(TreeNode* root) {
//	if (root == NULL) {
//		return;
//	}
//
//	stack<TreeNode*> nodeStack1, nodeStack2;
//	nodeStack1.push(root);
//
//	while (!nodeStack1.empty()) {
//		TreeNode* currentNode = nodeStack1.top();
//		nodeStack1.pop();
//		nodeStack2.push(currentNode);
//
//		if (currentNode->left) {
//			nodeStack1.push(currentNode->left);
//		}
//		if (currentNode->right) {
//			nodeStack1.push(currentNode->right);
//		}
//	}
//
//	while (!nodeStack2.empty()) {
//		cout << nodeStack2.top()->data << " ";
//		nodeStack2.pop();
//	}
//}
//
//// 求树高
//int treeHeight(TreeNode* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	return max(treeHeight(root->left), treeHeight(root->right)) + 1;
//}
//
//// 统计叶子总数
//int countLeaves(TreeNode* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	if (root->left == NULL && root->right == NULL) {
//		return 1;
//	}
//	return countLeaves(root->left) + countLeaves(root->right);
//}
//
//// 输出二叉树（前序遍历）
//void printTree(TreeNode* root) {
//	if (root == NULL) {
//		return;
//	}
//	cout << root->data << " ";
//	printTree(root->left);
//	printTree(root->right);
//}
//
//int main() {
//	TreeNode* root = NULL;
//	int choice, data, flag = 0;
//
//	while (true) {
//		cout << "1------建立一棵二叉树" << endl;
//		cout << "2------前序遍历递归算法" << endl;
//		cout << "3------前序遍历非递归算法" << endl;
//		cout << "4------中序遍历递归算法" << endl;
//		cout << "5------中序遍历非递归算法" << endl;
//		cout << "6------后序遍历递归算法" << endl;
//		cout << "7------后序遍历非递归算法" << endl;
//		cout << "8------求树高" << endl;
//		cout << "9------求叶子总数" << endl;
//		cout << "10-----输出二叉树" << endl;
//		cout << "11-----退出" << endl;
//		cout << "请输入您的选择：";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			int cnt;
//			cout << "请输入要插入的数据个数：";
//			cin >> cnt;
//			for (int i = 1; i <= cnt; i++) {
//				cout << "请输入要插入的第" << i << "个数据：";
//				cin >> data;
//				root = insertNode(root, data);
//			}
//			cout << "全部插入完毕！" << endl;
//			flag = 1;
//			system("pause");
//			system("cls");
//			break;
//		case 2:
//			if (flag) {
//				cout << "前序遍历递归算法结果：";
//				preOrderTraversalRecursive(root);
//				cout << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 3:
//			if (flag) {
//				cout << "前序遍历非递归算法结果：";
//				preOrderTraversalNonRecursive(root);
//				cout << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 4:
//			if (flag) {
//				cout << "中序遍历递归算法结果：";
//				inOrderTraversalRecursive(root);
//				cout << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 5:
//			if (flag) {
//				cout << "中序遍历非递归算法结果：";
//				inOrderTraversalNonRecursive(root);
//				cout << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 6:
//			if (flag) {
//				cout << "后序遍历递归算法结果：";
//				postOrderTraversalRecursive(root);
//				cout << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 7:
//			if (flag) {
//				cout << "后序遍历非递归算法结果：";
//				postOrderTraversalNonRecursive(root);
//				cout << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 8:
//			if (flag) {
//				cout << "树高为：" << treeHeight(root) << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 9:
//			if (flag) {
//				cout << "叶子总数为：" << countLeaves(root) << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 10:
//			if (flag) {
//				cout << "二叉树为：";
//				printTree(root);
//				cout << endl;
//			}
//			else cout << "当前未创建树" << endl;
//			system("pause");
//			system("cls");
//			break;
//		case 11:
//			cout << "退出程序" << endl;
//			return 0;
//		default:
//			cout << "无效的选择，请重新输入！" << endl;
//			system("pause");
//			system("cls");
//			break;
//		}
//	}
//	return 0;
//}
