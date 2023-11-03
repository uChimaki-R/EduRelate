//条件编译省略

#include"reader.h"
#include<iostream>

using namespace std;


const int Maxr = 100;

class RDatabase
{
private:
	int top;
	Reader read[Maxr];

public:
	RDatabase();
	void clear();//全部删除

	void delete_one_reader(Reader* num);//删除单独的一本

	int addreader(int n, char* na);
	Reader* query(int readerid);
	void list();
	void readerdata();
	
	


	
	void MySort();//排序函数，还在准备实现
		
	~RDatabase();




};
