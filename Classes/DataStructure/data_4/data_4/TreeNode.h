#pragma once
#include<iostream>
#include"Student.h"
using namespace std;

struct TreeNode {
	Student data;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
};

// 创建新节点
TreeNode* createNode(Student& data);

// 插入节点
TreeNode* insertNode(TreeNode* root, Student& data);

// 前序遍历递归算法
void preOrderTraversalRecursive(TreeNode* root);

// 查找数据
TreeNode* searchNode(TreeNode* root, string id);

// 删除数据
TreeNode* deleteNode(TreeNode* root, string& id);
