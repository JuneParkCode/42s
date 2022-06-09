#include "BinarySearchTree.hpp"
#include <random>
#include <iostream>

using namespace std;

int	main(void)
{
	BST<int> myBST;
	const int TEST_SIZE = 1000;

	for (int i = 0; i < TEST_SIZE; ++i)
	{
		int n =	rand() % 100000;
		myBST.insertItem(n);
		cout << n << endl;
	}
}
