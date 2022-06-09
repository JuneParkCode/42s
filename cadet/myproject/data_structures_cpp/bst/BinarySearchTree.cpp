#include "BinarySearchTree.hpp"

template<class ItemType>
BST<ItemType>::BST()
{
	const int MAX_SIZE = 500;
	// DEFAULT BST TREE SIZE IS 500
	maxSizeOfTree = MAX_SIZE;
	treeData = new Node[MAX_SIZE];
	numberOfItemsInTree = 0;
	currentNumberOfItem = -1;
	for (int nodeIdx = 0; nodeIdx < MAX_SIZE; ++nodeIdx)
	{
		treeData[nodeIdx] = Node(0,0);
	}
}

template<class ItemType>
BST<ItemType>::BST(const unsigned int size)
{
	maxSizeOfTree = size;
	treeData = new Node[size];
	numberOfItemsInTree = 0;
	currentNumberOfItem = -1;
	for (int nodeIdx = 0; nodeIdx < maxSizeOfTree; ++nodeIdx)
	{
		treeData[nodeIdx] = Node(0, nodeIdx, 0);
	}
}

template<class ItemType>
BST<ItemType>::BST(const BST<ItemType> &targetBST)
{
	copy(targetBST);
}

template<class ItemType>
BST<ItemType>::~BST()
{
	delete[] (treeData);
}

template<class ItemType>
void BST<ItemType>::insertItem(const ItemType item)
{
	if (isFull())
		throw (FULL_BST);
	if (numberOfItemsInTree == 0)
	{
		treeData[++numberOfItemsInTree] = item;
		return ;
	}
	else
	{
		Node *currentNode;
		unsigned int nodePos = 1;
		currentNode = &treeData[nodePos];
		while (currentNode->isMarked)
		{
			if (currentNode->data < item)
			{
				nodePos = nodePos * 2;
				currentNode = &treeNode[nodePos];
			}
			else if (currentNode->data == item)
			{
				return ; // THERE IS NO DUPLICATES
			}
			else
			{
				nodePos = nodePos * 2 + 1;
				currentNode = &treeNode[nodePos];
			}
		}
		currentNode->data = item;
		currentNode->isMarked = true;
		++numberOfItemsInTree;
	}
}

template<class ItemType>
void BST<ItemType>::deleteItem(const ItemType item)
{

}

template<class ItemType>
bool BST<ItemType>::findItem(const ItemType item) const
{

}

template<class ItemType>
bool BST<ItemType>::isEmpty() const
{
	return (numberOfItemsInTree == 0);
}

template<class ItemType>
bool BST<ItemType>::isFull() const
{
	return (numberOfItemsInTree >= maxSizeOfTree);
}

template<class ItemType>
void BST<ItemType>::resetIterator()
{
	currentNumberOfItem = 0;
}

template<class ItemType>
void BST<ItemType>::printTree() const
{
	// 작은 원소부터...
}

template<class ItemType>
ItemType BST<ItemType>::getNextItem() const
{

}

template<class ItemType>
BST<ItemType> BST<ItemType>::operator=(BST<ItemType> &targetTree)
{

}
