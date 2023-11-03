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
	cout << "������" << sarr[num].name << endl;
	cout << "�Ա�";
	if (sarr[num].sex)
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "Ů" << endl;
	}
	cout << "ѧ�ţ�" << sarr[num].id << endl;
	cout << "C���Գɼ���" << sarr[num].score[0] << endl;
	cout << "��ѧ�ɼ���" << sarr[num].score[1] << endl;
	cout << "��������۳ɼ���" << sarr[num].score[2] << endl;
}

void input_ifo(int num)
{
	cout << "��ǰ��������� " << num << " λͬѧ����Ϣ" << endl;
	Stu s;
	cout << "�������ͬѧ�����֣�";
	cin >> s.name;
	cout << "�������ͬѧ��ѧ�ţ�";
	cin >> s.id;
	char c;
	while (1)
	{
		cout << "�������ͬѧ���Ա�1������ 0��Ů������";
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
			cout << "�����Ա����������ԣ�" << endl;
		}
	}
	cout << "�������ͬѧ��C���Գɼ���";
	cin >> s.score[0];
	cout << "�������ͬѧ����ѧ�ɼ���";
	cin >> s.score[1];
	cout << "�������ͬѧ�ļ�������۳ɼ���";
	cin >> s.score[2];
	sarr[num] = s;
	cout << "��ͬѧ��Ϣ¼����ϣ���Ϣ���£�" << endl;
	show_ifo(num);
}

void print_ifo()
{
	for (int i = 1; i <= stu_num; i++)
	{
		cout << "�� " << i << " λѧ����Ϣ���£�" << endl;
		show_ifo(i);
	}
}

int find_by_id()
{
	cout << "������ѧ����ѧ�ţ�";
	string id;
	cin >> id;
	for (int i = 1; i <= stu_num; i++)
	{
		if (sarr[i].id==id)
		{
			cout << "�ҵ��˸�ѧ������Ϣ���£�" << endl;
			show_ifo(i);
			return i;
		}
	}
	cout << "��Ǹ��û�и�ѧ������Ϣ��" << endl;
	return 0;
}

void change_ifo()
{
	int num = find_by_id();
	if (num)
	{
		cout << "�������µ�ѧ����Ϣ��" << endl;
		input_ifo(num);
	}

}

int main()
{
	cout << "����ѧ��������";
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
	cout << "1����ӡ����ѧ����Ϣ 2�����ҵ���ѧ����Ϣ 3���޸ĵ���ѧ����Ϣ 0���˳�����" << endl;
		cout << "��ѡ����Ҫ�Ĺ��ܣ�";
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
			cout << "��лʹ�ã�" << endl;
			system("pause");
			exit(0);
		}
		else
		{
			cout << "�������������ԣ�" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}