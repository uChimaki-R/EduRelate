//��������ʡ��

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
	void clear();//ȫ��ɾ��

	void delete_one_reader(Reader* num);//ɾ��������һ��

	int addreader(int n, char* na);
	Reader* query(int readerid);
	void list();
	void readerdata();
	
	


	
	void MySort();//������������׼��ʵ��
		
	~RDatabase();




};
