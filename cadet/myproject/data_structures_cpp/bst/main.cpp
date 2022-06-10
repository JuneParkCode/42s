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

	std::cout << "IN_ORDER TEST\n";
	int item;
	myBST.resetQueue(IN_ORDER);
	std::cout << "RESET OK\n";
	while (!myBST.getNextItem(IN_ORDER,item))
	{
		std::cout << item << std::endl;
	}
	std::cout << item << std::endl;
	BST<int> newBST = myBST;
	newBST.resetQueue(IN_ORDER);
	std::cout << "RESET OK\n";
	while (!newBST.getNextItem(IN_ORDER,item))
	{
		std::cout << item << std::endl;
	}
	std::cout << item << std::endl;
}
