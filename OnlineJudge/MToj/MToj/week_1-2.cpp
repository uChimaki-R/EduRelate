#include<iostream>
#include<algorithm>
using namespace std;

//���賵û����ײ�����һ�£�ֻ��Ҫ�������˳�����

//1����������˳���ÿ��λ��С�����
//2�������복��λ�����򣨵ó�Ҫ��ӡ��С��˳�������λ�õĶ�Ӧ��
//                      ���ڱ��⣬����4 5 7 2 6������Ĵ�ӡ˳��Ϊ1 2 3 4 5
//                      ��ͨ��λ�������Ϊ2 4 5 6 7 �õ���ӡ˳��Ϊ4 1 2 5 3������һ��λ�ô���С����4����ӡ��
//                      ����С������ײ�����λ�ò��䣬���Խ����λ��Ҳͨ��λ�����򣬾Ϳ���һһ��Ӧ������Ĵ�ӡ˳��
//3�����������λ�����򣬴�ʱ�ȼ���ÿ������ǰ��λ��һһ��Ӧ
//4������ӡ˳��ת��
//5�����ݴ�ӡ˳��������������
//6����ӡ���

class Car
{
public:
	Car()
	{
		this->id = -1;
		this->towards = 2;
		this->place = 1010;
	}
	int id;
	int towards;
	int place;
};

Car first[1010];
Car final[1010];

class sort_by_place
{
public:
	bool operator()(Car& c1, Car& c2)
	{
		return c1.place < c2.place;
	}
};

class sort_by_id
{
public:
	bool operator()(Car& c1, Car& c2)
	{
		return c1.id < c2.id;
	}
};

int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> first[i].place >> first[i].towards;
		first[i].id = i;
		final[i].place = (first[i].place + t * first[i].towards);//ֱ�ӿ��Եó�����һ�����Ľ���λ��
		final[i].towards = first[i].towards;
	}
	sort(first + 1, first + 1 + n, sort_by_place());
	sort(final + 1, final + 1 + n, sort_by_place());
	for (int i = 1; i <= n; i++)
	{
		//ת��id�ţ���ӡ˳��
		final[i].id = first[i].id;
	}
	sort(final + 1, final + 1 + n, sort_by_id());//��id˳���ţ�����ӡ˳��
	//ͬһλ�÷�����Ϊ0
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (final[i].place == final[j].place)
			{
				final[i].towards = 0;
				final[j].towards = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << final[i].place << " " << final[i].towards << endl;
	}
	return 0;
}






//#include<iostream>
//#include<map>
//#include<algorithm>
//using namespace std;
//
//
//class Car
//{
//public:
//	Car()
//	{
//		this->is_move = false;
//		this->place = -1;
//		this->towards = 2;
//	}
//	bool operator<(Car c)
//	{
//		return this->place < c.place;
//	}
//	bool is_move;
//	int towards;
//	int place;
//};
//
//int n, times;
//int place[106];
//Car car_arr[1001];
//multimap<int, int>m1;
//multimap<int, int>m2;
//
//bool is_reverse(int pos)
//{
//	if (place[pos] >= 2)
//	{
//		return true;
//	}
//	return false;
//}
//
//void Go_one_time()
//{
//	for (int i = 1; i < 106; i++)
//	{
//		if (place[i])
//		{
//			//�г�
//			//�ƶ���������г�
//			for (int j = 1; j <= n; j++)
//			{
//				if ((car_arr[j].place == i) && (car_arr[j].is_move == false))
//				{
//					car_arr[j].is_move = true;
//					switch (car_arr[j].towards)
//					{
//					case 1:
//						//����
//						place[i]--;
//						place[i + 1]++;
//						car_arr[j].place++;
//						if (is_reverse(i + 1))
//						{
//							//�ұ��г�
//							car_arr[j].towards = -1;
//						}
//						break;
//					case -1:
//						//����
//						place[i]--;
//						place[i - 1]++;
//						car_arr[j].place--;
//						if (is_reverse(i - 1))
//						{
//							//����г�
//							car_arr[j].towards = 1;
//						}
//						break;
//					}
//				}
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		car_arr[i].is_move = false;
//	}
//}
//
//int main()
//{
//	cin >> n >> times;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> car_arr[i].place >> car_arr[i].towards;
//		place[car_arr[i].place]++;
//		m1.insert(make_pair(car_arr[i].place, i));
//	}
//	while (times--)
//	{
//		Go_one_time();
//	}
//	for (int i = 1; i < 106; i++)
//	{
//		if (place[i] >= 2)
//		{
//			//��λ���ж�����
//			for (int j = 1; j <= n; j++)
//			{
//				if (car_arr[j].place == i)
//				{
//					car_arr[j].towards = 0;
//				}
//			}
//		}
//	}
//	int i = 1;
//	sort(car_arr + 1, car_arr + n + 1);
//	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++)
//	{
//		m2.insert(make_pair(car_arr[i].place, it->second));
//		i++;
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		int flag = 1;
//		for (map<int, int>::iterator it = m2.begin(); it != m2.end(); it++)
//		{
//			if (it->second == i && flag)
//			{
//				for (int j = 1; j <= n; j++)
//				{
//					if (car_arr[j].place == it->first)
//					{
//						cout << car_arr[j].place << " " << car_arr[j].towards;
//						flag = 0;
//						break;
//					}
//				}
//			}
//		}
//		if (i != n)
//		{
//			cout << endl;
//		}
//	}
//	return 0;
//}
//
//
//
//
////#include<iostream>
////using namespace std;
////
////
////class Car
////{
////public:
////	Car()
////	{
////		this->is_move = false;
////		this->place = -1;
////		this->towards = 2;
////	}
////	bool is_move;
////	int towards;
////	int place;
////};
////
////int n, times;
////int place[106];
////Car car_arr[1001];
////
////
////void Go_one_time()
////{
////	for (int i = 1; i < 106; i++)
////	{
////		if (place[i])
////		{
////			//�г�
////			//�ƶ���������г�
////			for (int j = 1; j <= n; j++)
////			{
////				if ((car_arr[j].place == i) && (car_arr[j].is_move == false))
////				{
////					car_arr[j].is_move = true;
////					int flag = 1;
////					switch (car_arr[j].towards)
////					{
////					case 1:
////						//����
////						for (int k = j + 1; k <= n; k++)
////						{
////							if ((car_arr[k].place == i + 1) && (car_arr[k].is_move == false) && (car_arr[k].towards == -1))
////							{
////								car_arr[j].towards = -1;
////								car_arr[k].towards = 1;
////								car_arr[k].is_move = true;
////								flag = 0;
////							}
////						}
////
////
////						if (flag)
////						{
////							place[i]--;
////							place[i + 1]++;
////							car_arr[j].place++;
////						}
////						break;
////					case -1:
////						//����
////						for (int k = j + 1; k <= n; k++)
////						{
////							if ((car_arr[k].place == i - 1) && (car_arr[k].is_move == false) && (car_arr[k].towards == 1))
////							{
////								car_arr[j].towards = 1;
////								car_arr[k].towards = -1;
////								car_arr[k].is_move = true;
////								flag = 0;
////							}
////						}
////
////
////						if (flag)
////						{
////							place[i]--;
////							place[i - 1]++;
////							car_arr[j].place--;
////						}
////						break;
////					}
////				}
////			}
////		}
////	}
////	for (int i = 1; i <= n; i++)
////	{
////		car_arr[i].is_move = false;
////	}
////}
////
////int main()
////{
////	cin >> n >> times;
////	for (int i = 1; i <= n; i++)
////	{
////		cin >> car_arr[i].place >> car_arr[i].towards;
////		place[car_arr[i].place]++;
////	}
////	while (times--)
////	{
////		Go_one_time();
////	}
////	for (int i = 1; i < 106; i++)
////	{
////		if (place[i] >= 2)
////		{
////			//��λ���ж�����
////			for (int j = 1; j <= n; j++)
////			{
////				if (car_arr[j].place == i)
////				{
////					car_arr[j].towards = 0;
////				}
////			}
////		}
////	}
////	for (int i = 1; i <= n; i++)
////	{
////		cout << car_arr[i].place << " " << car_arr[i].towards;
////		if (i != n)
////		{
////			cout << endl;
////		}
////	}
////	return 0;
////}
//
//
//
//
//
//
////#include<iostream>
////using namespace std;
////
////
////class Car
////{
////public:
////	Car()
////	{
////		this->is_together = false;
////		this->is_move = false;
////		this->place = -1;
////		this->towards = 2;
////	}
////	bool is_together;
////	bool is_move;
////	int towards;
////	int place;
////};
////
////int n, times;
////int place[106];
////Car car_arr[1001];
////
////bool is_reverse(int pos)
////{
////	if (place[pos] >= 2)
////	{
////		return true;
////	}
////	return false;
////}
////
////void Go_one_time()
////{
////	for (int i = 1; i < 106; i++)
////	{
////		if (place[i])
////		{
////			//�г�
////			//�ƶ���������г�
////			for (int j = 1; j <= n; j++)
////			{
////				if ((car_arr[j].place == i) && (car_arr[j].is_move == false))
////				{
////					car_arr[j].is_move = true;
////					switch (car_arr[j].towards)
////					{
////					case 1:
////						//����
////						place[i]--;
////						place[i + 1]++;
////						car_arr[j].place++;
////						if (is_reverse(i + 1))
////						{
////							//�ұ��г�
////							car_arr[j].is_together = true;
////							car_arr[j].towards = -1;
////						}
////						else
////						{
////							car_arr[j].is_together = false;
////						}
////						break;
////					case -1:
////						//����
////						place[i]--;
////						place[i - 1]++;
////						car_arr[j].place--;
////						if (is_reverse(i - 1))
////						{
////							//����г�
////							car_arr[j].is_together = true;
////							car_arr[j].towards = 1;
////						}
////						else
////						{
////							car_arr[j].is_together = false;
////						}
////						break;
////					}
////				}
////			}
////		}
////	}
////	for (int i = 1; i <= n; i++)
////	{
////		car_arr[i].is_move = false;
////	}
////}
////
////int main()
////{
////	cin >> n >> times;
////	for (int i = 1; i <= n; i++)
////	{
////		cin >> car_arr[i].place >> car_arr[i].towards;
////		place[car_arr[i].place]++;
////	}
////	for (int i = 1; i < 106; i++)
////	{
////		if (place[i] >= 2)
////		{
////			//��λ���ж�����
////			for (int j = 1; j <= n; j++)
////			{
////				if (car_arr[j].place == i)
////				{
////					car_arr[j].is_together = true;
////				}
////			}
////		}
////	}
////	while (times--)
////	{
////		Go_one_time();
////	}
////	for (int i = 1; i < 106; i++)
////	{
////		if (place[i] >= 2)
////		{
////			//��λ���ж�����
////			for (int j = 1; j <= n; j++)
////			{
////				if (car_arr[j].place == i)
////				{
////					car_arr[j].is_together = true;
////					car_arr[j].towards = 0;
////				}
////			}
////		}
////	}
////	for (int i = 1; i <= n; i++)
////	{
////		cout << car_arr[i].place << " " << car_arr[i].towards;
////		if (i != n)
////		{
////			cout << endl;
////		}
////	}
////	return 0;
////}