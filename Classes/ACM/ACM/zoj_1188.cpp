#include <iostream>
#include <algorithm>
using namespace std;

struct DNA
{
    int id;
    string dna;
    int cnt;
};

int getcnt(string &s)
{
    int cnt = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[j] - s[i] >= 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

bool mycompare(const DNA &d1, const DNA &d2)
{
    if (d1.cnt == d2.cnt)
    {
        return d1.id < d2.id;
    }
    return d1.cnt > d2.cnt;
}

void printdna(const DNA &d)
{
    cout << d.dna << endl;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        DNA dnas[1005];
        int len, n, tdna = 0;
        cin >> len >> n;
        for (int j = 1; j <= n; j++)
        {
            DNA d;
            cin >> d.dna;
            d.id = j;
            d.cnt = getcnt(d.dna);
            dnas[tdna++] = d;
        }
        sort(dnas, dnas + tdna, mycompare);
        for_each(dnas, dnas + tdna, printdna);
        if (i != N - 1)
        {
            cout << endl;
        }
    }
    return 0;
}