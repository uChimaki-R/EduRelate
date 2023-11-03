#include"headf.h"


int addfactrl(int max)
{
	int sum = 0;
	for (int i = 1; i <= max; i++)
	{
		sum += factorial(i);
	}
	return sum;
}