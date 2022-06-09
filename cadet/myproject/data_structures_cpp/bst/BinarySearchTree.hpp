class FULL_BST{};
class EMPTY_BST{};

template<class ItemType>
struct Node
{
	ItemType data;
	unsigned int nodeIdx;
	bool isMarked;
	Node(ItemType item, unsigned int idx, bool booleanValue) :
		data{item}, nodeIdx{idx},isMarked{booleanValue}{}
};

template<class ItemType>
class BST
{
private:
	int	maxSizeOfTree;
	Node *treeData;
	int numberOfItemsInTree;
	int currentNumberOfItem;
public:
	BST();
	BST(const unsigned int size);
	BST(const BST<ItemType> &targetBST);
	~BST();
	void insertItem(const ItemType item);
	void deleteItem(const ItemType item);
	bool findItem(const ItemType item) const;
	bool isEmpty() const;
	bool isFull() const;
	ItemType getNextItem() const;
	void printTree() const;
	void resetIterator();
	void copy(const BST<ItemType> &targetTree);
	BST<ItemType> operator=(BST<ItemType> &targetTree);
	// // ITERATOR FOR CONTAINER...
	// class iterator
	// {
	// public:
	// 	iterator();
	// 	iterator& operator++();
	// 	ItemType& operator*() const;
	// 	bool operator!=(const iterator &targetIterator) const;
	// };
};
