#include <random>
#include <iostream>
#include "BinarySearchTree.hpp"

int	main(void)
{
	BST<int> myBST;
	const int TEST_SIZE = 10;

	for (int i = 0; i < TEST_SIZE; ++i)
	{
		int n =	rand() % 100000;
		myBST.insertItem(n);
		std::cout << n << std::endl;
	}

	std::cout << "POST ORDER TEST\n";
	int item;
	myBST.resetQueue(POST_ORDER);
	while (!myBST.getNextItem(POST_ORDER,item))
	{
		std::cout << item << std::endl;
	}
}
