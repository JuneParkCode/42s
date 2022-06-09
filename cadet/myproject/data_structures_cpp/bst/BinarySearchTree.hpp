
template<class ItemType>
class BST
{
public:
	BST();
	BST(unsigned int size);
	~BST();
	void insertItem(const ItemType item);
	void deleteItem(const ItemType item);
	void resizeTree(const unsigned int size);
	bool findItem(const ItemType item);
	ItemType getNextItem() const;
	void printTree() const;
	void resetIterator();
	BST<ItemType> operator=(BST<ItemType> &target);
private:
	int	SIZE_OF_TREE;
	ItemType *treeData;
	int numberOfItemsInTree;
	int currentNumberOfItem;
};
