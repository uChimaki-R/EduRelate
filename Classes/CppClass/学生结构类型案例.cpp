#include<iostream>
#include<vector>
using namespace std;

typedef struct Student
{
	string id;
	string name;
	int sex = 1;
	int score[3] = { 0 };
}Stu;

int n;
int stu_num = 1;
Stu sarr[100];

void show_ifo(int num)
{
	cout << "姓名：" << sarr[num].name << endl;
	cout << "性别：";
	if (sarr[num].sex)
	{
		cout << "男" << endl;
	}
	else
	{
		cout << "女" << endl;
	}
	cout << "学号：" << sarr[num].id << endl;
	cout << "C语言成绩：" << sarr[num].score[0] << endl;
	cout << "数学成绩：" << sarr[num].score[1] << endl;
	cout << "计算机导论成绩：" << sarr[num].score[2] << endl;
}

void input_ifo(int num)
{
	cout << "当前正在输入第 " << num << " 位同学的信息" << endl;
	Stu s;
	cout << "请输入该同学的名字：";
	cin >> s.name;
	cout << "请输入该同学的学号：";
	cin >> s.id;
	char c;
	while (1)
	{
		cout << "请输入该同学的性别（1：男生 0：女生）：";
		cin >> c;
		if (c == '1')
		{
			s.sex = 1;
			break;
		}
		else if (c == '0')
		{
			s.sex = 0;
			break;
		}
		else
		{
			cout << "输入性别有误，请重试！" << endl;
		}
	}
	cout << "请输入该同学的C语言成绩：";
	cin >> s.score[0];
	cout << "请输入该同学的数学成绩：";
	cin >> s.score[1];
	cout << "请输入该同学的计算机导论成绩：";
	cin >> s.score[2];
	sarr[num] = s;
	cout << "该同学信息录入完毕，信息如下：" << endl;
	show_ifo(num);
}

void print_ifo()
{
	for (int i = 1; i <= stu_num; i++)
	{
		cout << "第 " << i << " 位学生信息如下：" << endl;
		show_ifo(i);
	}
}

int find_by_id()
{
	cout << "请输入学生的学号：";
	string id;
	cin >> id;
	for (int i = 1; i <= stu_num; i++)
	{
		if (sarr[i].id==id)
		{
			cout << "找到了该学生，信息如下：" << endl;
			show_ifo(i);
			return i;
		}
	}
	cout << "抱歉，没有该学生的信息。" << endl;
	return 0;
}

void change_ifo()
{
	int num = find_by_id();
	if (num)
	{
		cout << "请输入新的学生信息：" << endl;
		input_ifo(num);
	}

}

int main()
{
	cout << "输入学生人数：";
	cin >> n;
	while (n--)
	{
		input_ifo(stu_num);
		stu_num++;
		system("pause");
		system("cls");
	}
	stu_num--;
	while (1)
	{
	cout << "1、打印所有学生信息 2、查找单个学生信息 3、修改单个学生信息 0、退出程序" << endl;
		cout << "请选择想要的功能：";
		char c;
		cin >> c;
		if (c == '1')
		{
			print_ifo();
			system("pause");
			system("cls");
		}
		else if (c == '2')
		{
			find_by_id();
			system("pause");
			system("cls");
		}
		else if (c == '3')
		{
			change_ifo();
			system("pause");
			system("cls");
		}
		else if (c == '0')
		{
			cout << "感谢使用！" << endl;
			system("pause");
			exit(0);
		}
		else
		{
			cout << "输入有误，请重试！" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}