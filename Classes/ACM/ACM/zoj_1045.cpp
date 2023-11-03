#include<iostream>
using namespace std;

int get_card(int times, double input)
{
	if(input<(1.0/(times+1)))
	{
		return 1;
	}
	return get_card(times + 1, input - (1.0 / (times + 1))) + 1;
}

int main()
{
	double input;
	cin >> input;
	while (input != 0)
	{
		cout << get_card(1,input) << " card(s)" << endl;
		cin >> input;
	}
	return 0;
}





// #include<iostream>
// using namespace std;

// double knew_length[1000];

// double length(int i)
// {
// 	if (knew_length[i])
// 	{
// 		return knew_length[i];
// 	}
// 	if (i == 1)
// 	{
// 		return 1.0 / 2.0;
// 	}
// 	else
// 	{
// 		knew_length[i] = 1.0 / (i + 1) + length(i - 1);
// 		return knew_length[i];
// 	}
// }

// int main()
// {
// 	double input;
// 	cin >> input;
// 	while (input != 0)
// 	{
// 		int i = 1;
// 		while (length(i) < input)
// 		{
// 			i++;
// 		}
// 		cout << i << " card(s)" << endl;
// 		cin >> input;
// 	}
// 	return 0;
// }