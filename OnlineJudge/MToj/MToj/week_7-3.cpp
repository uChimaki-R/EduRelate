#include<iostream>
#include<queue>
using namespace std;

const int N = 15005;
int pos;

struct File
{
	int id, come, use, level;
	bool operator<(const File& f)const
	{
		if (this->level != f.level)
		{
			return this->level < f.level;
		}
		return this->come > f.come;
	}
}files[N];

priority_queue<File>heap;

int main()
{
	int id, come, use, level;
	while (cin >> id >> come >> use >> level)
	{
		files[pos++] = { id,come,use,level };
	}
	heap.push(files[0]);
	int now = files[0].come;
	for (int i = 1; i < pos; i++)
	{
		while (!heap.empty() && (files[i].come >= now + heap.top().use))
		{
			now += heap.top().use;
			cout << heap.top().id << " " << now << endl;
			heap.pop();
		}
		if (!heap.empty())
		{
			File f = heap.top();
			heap.pop();
			f.use -= (files[i].come - now);
			heap.push(f);
		}
		now += (files[i].come - now);//now = files[i].come
		heap.push(files[i]);
	}
	while (!heap.empty())
	{
		now += heap.top().use;
		cout << heap.top().id << " " << now << endl;
		heap.pop();
	}
	return 0;
}