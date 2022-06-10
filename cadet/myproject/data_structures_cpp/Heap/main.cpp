#include <iostream>
#include <random>
#include "Heap.hpp"

#define TC_SIZE 10

using namespace std;

int main(void)
{
	Heap<int> testHeap;

	for (int i = 0; i < TC_SIZE; ++i)
	{
		int x = i;
		cout << x << endl;;
		testHeap.insertItem(x);
	}

	testHeap.deleteItem(3);
	cout << endl;
	while (!testHeap.isEmpty())
	{
		cout << testHeap.pop() << endl;;
	}
}
