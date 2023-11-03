#pragma once
#include<iostream>
using namespace std;

template <class T>
class Stack {
public:
	int maxSize = 100;
	T* arrs = nullptr;
	Stack();
	void push(const T x);
	void pop();
	T top();
	bool empty();
	int size();
	~Stack();
};

template <class T>
Stack<T>::Stack()
{
	arrs = new T[maxSize];
	arrs[0] = 0;
}

template <class T>
void Stack<T>::push(const T x)
{
	if (arrs[0] < maxSize - 1) arrs[++arrs[0]] = x;
}

template <class T>
void Stack<T>::pop()
{
	if (arrs[0]) arrs[0]--;
}

template <class T>
T Stack<T>::top()
{
	return arrs[arrs[0]];
}

template <class T>
bool Stack<T>::empty()
{
	return !arrs[0];
}

template <class T>
int Stack<T>::size()
{
	return arrs[0];
}

template <class T>
Stack<T>::~Stack()
{
	delete[]arrs;
}
