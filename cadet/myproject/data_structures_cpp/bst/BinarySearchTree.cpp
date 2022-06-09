#include "BinarySearchTree.hpp"

template<class ItemType>
BST<ItemType>::BST()
{
	(this->numberOfItemsInTree) = 0;
	(this->root) = nullptr;
}

template<class ItemType>
BST<ItemType>::BST(const BST<ItemType> &targetBST)
{
	this->copy(targetBST);
}

/* FOR DESTRUCTOR */
template<class ItemType>
static void deleteTree(TreeNode<ItemType> *tree)
{
	if (tree == nullptr)
	{
		return ;
	}
	else
	{
		// RECURSIVE...
		deleteTree(tree->left);
		deleteTree(tree->right);
		delete (tree);
	}
}

template<class ItemType>
BST<ItemType>::~BST()
{
	deleteTree(this->root);
}
/* END */

// DONE
template<class ItemType>
void BST<ItemType>::insertItem(const ItemType item)
{
	// ERROR HANDLING
	if (this->isFull())
		throw (FULL_BST());
	if (this->findItem(item))
		return ; // DISTINCT!!
	// Find Position
	TreeNode<ItemType> *node = (this->root);
	TreeNode<ItemType> *parentNode;
	while (node)
	{
		parentNode = node;
		if (item < node->data)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}
	// Insert
	TreeNode<ItemType> *newNode = new TreeNode<ItemType>(item, parentNode);
	if (parentNode->data < item)
	{
		parentNode->right = newNode;
	}
	else
	{
		parentNode->left = newNode;
	}
	++(this->numberOfItemsInTree);
}
/* FOR DELETE ITEM FUNCTION */
template<class ItemType>
static ItemType getPredecessor(TreeNode<ItemType> &tree, const ItemType item)
{
	TreeNode<ItemType> *node = tree;
	while (node->right)
	{
		node = node->right;
	}
	return (node->data);
}

template<class ItemType>
static void deleteNode(TreeNode<ItemType> &tree, const ItemType item)
{
	TreeNode<ItemType> *tempPtr = tree;
	if (tree->left == nullptr)
	{
		tree = tree->right;
		delete (tempPtr);
	}
	else if (tree->right == nullptr)
	{
		tree = tree->left;
		delete (tempPtr);
	}
	else
	{
		tree->data = getPredecessor(tree->left, item);
		deleteProcess(tree->left, tree->data);
	}
}

template<class ItemType>
static void deleteProcess(TreeNode<ItemType> &tree, const ItemType item)
{
	// FIND NODE
	if (item > tree->data)
	{
		deleteProcess(tree->right);
	}
	else if (item < tree->data)
	{
		deleteProcess(tree->left);
	}
	else
	{
		// if FOUND then DELETE NODE
		deleteNode(tree);
	}
}

// DONE
template<class ItemType>
void BST<ItemType>::deleteItem(const ItemType item)
{
	if (this->isEmpty())
		throw (EMPTY_BST());
	if (!this->findItem(item))
		return ;
	deleteProcess((this->root), item);
	--(this->numberOfItemsInTree);
}
/* END */

// DONE
template<class ItemType>
bool BST<ItemType>::findItem(const ItemType item) const
{
	TreeNode<ItemType> *node = (this->root);
	bool found = false;

	while (!found && node)
	{
		if (item > node->data)
		{
			node = node->right;
		}
		else if (item == node->data)
		{
			found = true;
		}
		else
		{
			node = node->left;
		}
	}
	return (found);
}

// DONE
template<class ItemType>
bool BST<ItemType>::isEmpty() const
{
	return (numberOfItemsInTree == 0);
}

// DONE
template<class ItemType>
bool BST<ItemType>::isFull() const
{
	try
	{
		TreeNode<ItemType> tmp = new TreeNode<ItemType>;
		delete tmp;
    	return (false);
	}
	catch(const std::bad_alloc exception)
	{
		return (true);
	}
}

template<class ItemType>
void BST<ItemType>::resetQueue(Orders order)
{
	// clear queue...
	switch (order)
	{
	case PRE_ORDER:
		while(!(this->preQueue).empty())
		{
			(this->preQueue).pop();
		}
		fillPreOrderQueue((this->root), (this->preQueue));
		break;
	case IN_ORDER:
		while(!(this->inQueue).empty())
		{
			(this->inQueue).pop();
		}
		fillInOrderQueue((this->root), (this->inQueue));
		break;
	case POST_ORDER:
		while(!(this->postQueue).empty())
		{
			(this->postQueue).pop();
		}
		fillPostOrderQueue((this->root), (this->postQueue));
		break;
	}
}

template<class ItemType>
void fillPreOrderQueue(TreeNode<ItemType> &tree, std::queue<ItemType> que)
{
	if (tree != nullptr)
	{
		que.push(tree->data);
		fillPreOrderQueue(tree->left, que);
		fillPreOrderQueue(tree->right, que);
	}
}

template<class ItemType>
void fillInOrderQueue(TreeNode<ItemType> &tree, std::queue<ItemType> que)
{
	if (tree != nullptr)
	{
		fillInOrderQueue(tree->left, que);
		que.push(tree->data);
		fillInOrderQueue(tree->right, que);
	}
}

template<class ItemType>
void fillPostOrderQueue(TreeNode<ItemType> &tree, std::queue<ItemType> que)
{
	if (tree != nullptr)
	{
		fillInOrderQueue(tree->left, que);
		fillInOrderQueue(tree->right, que);
		que.push(tree->data);
	}
}

template<class ItemType>
bool BST<ItemType>::getNextItem(Orders order, ItemType &item)
{
	switch (order)
	{
	case PRE_ORDER:
		item = (this->preQueue).pop();
		if ((this->preQueue).empty())
			return (true);
		break;
	case IN_ORDER:
		item = (this->inQueue).pop();
		if ((this->inQueue).empty())
			return (true);
		break;
	case POST_ORDER:
		item = (this->postQueue).pop();
		if ((this->postQueue).empty())
			return (true);
		break;
	}
	return (false);
}

// NOT_YET
template<class ItemType>
BST<ItemType> BST<ItemType>::operator=(BST<ItemType> &srcTree)
{
	copyTree(this, srcTree);
}

template<class ItemType>
unsigned int BST<ItemType>::getLength() const
{
	return (this->numberOfItemsInTree);
}

template<class ItemType>
void copyTree(const BST<ItemType> &dstTree, const BST<ItemType> &srcTree)
{
	ItemType item;

	if (dstTree.getLength() != 0)
	{
		return ; // COPY FAILED
	}
	srcTree.resetQueue(PRE_ORDER);
	while (!srcTree.getNextItem(PRE_ORDER, item))
	{
		dstTree.insertItem(item);
	}
}
