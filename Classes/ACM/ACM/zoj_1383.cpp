#include <iostream>
#include <vector>
using namespace std;

void get_one_place(int val, vector<int> &place)
{
    place.clear();
    int num = 0;
    while (val)
    {
        int s = val / 2;
        int y = val % 2;
        if (y)
        {
            place.push_back(num);
        }
        val /= 2;
        num++;
    }
}

int main()
{
    vector<int> place;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        get_one_place(input, place);
        for (vector<int>::iterator it = place.begin(); it != place.end(); it++)
        {
            if (it != place.begin())
            {
                cout << " ";
            }
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}