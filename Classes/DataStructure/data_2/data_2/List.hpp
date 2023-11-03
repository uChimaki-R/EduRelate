#pragma once
#include<iostream>
using namespace std;

template<class T>
class ListNode
{
public:
	T data;
	ListNode<T>* next = nullptr;
};

template<class T>
class List
{
public:
	int length = 0;
	ListNode<T>* first = nullptr;
	void insert_one(T& data);
	void delete_one(int idx);
};

template<class T>
void List<T>::insert_one(T& data) {
	ListNode<T>* new_node = new ListNode<T>;
	new_node->data = data;
	new_node->next = first;
	first = new_node;
	length++;
}

template<class T>
void List<T>::delete_one(int idx) {
	if (idx >= length)return;
	ListNode<T>* pos = first;
	ListNode<T>* last = nullptr;
	for (int i = 0; i < idx; i++)last = pos, pos = pos->next;
	if (last)last->next = pos->next;
	if (pos == first)first = first->next;  //可能就是第一个，直接delete会把first也delete，数据直接没了
	else delete pos;
}
