#pragma once
#include<iostream>
using namespace std;
#define DefaultSize 50


template <class T>
class Table
{
public:
	T* data;
	int MaxSize;
	int last;
	Table(int MaxSize = DefaultSize);
	/*int find(T& x);
	bool insert_one(T& x);*/
	~Table();
};


template <class T>
Table <T> ::Table(int sz) {
    if (sz > 0) {
        MaxSize = sz;  last = -1;
        data = new T[MaxSize];
        /*if (data == 0) {
            MaxSize = 0;   last = -1;
            return;
        }*/
    }
};


//template <class T>
//int Table <T> ::find(T& x) {
//    int  i = 0;
//    while (i <= last && data[i] != x)
//        i++;
//    if (i > last) return -1;
//    else return i;
//};
//
//
//template <class T>
//bool Table <T> ::insert_one(T& x) {
//    if (last == MaxSize - 1) return false;
//    data[++last] = x;
//}


template<class T>
Table<T>::~Table() {
    delete[]data;
}
