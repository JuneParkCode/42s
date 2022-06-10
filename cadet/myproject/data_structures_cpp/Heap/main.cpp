#include <iostream>
#include <random>
#include "Heap.hpp"

#define TC_SIZE 100

using namespace std;

int main(void)
{
	Heap<int> testHeap;

	for (int i = 0; i < TC_SIZE; ++i)
	{
		int x = random() % 1000;
		cout << x << endl;;
		testHeap.insertItem(x);
	}

	testHeap.deleteItem(3);
	cout << endl;
	int prev, cur;
	int i = 0;
	while (!testHeap.isEmpty())
	{
		cur = testHeap.pop();
		cout << cur << endl;
		if (i != 0 && cur > prev)
		{
			cout << "NOT SORTED!! " <<  prev << "," << cur << " \n" ;
			return (0);
		}
		++i;
		prev = cur;
	}
}
