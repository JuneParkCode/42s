#include <queue>

class FULL_BST{};
class EMPTY_BST{};

template<class ItemType>
struct TreeNode
{
	ItemType data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(ItemType d) :
		data(d), left(nullptr), right(nullptr) {}
};

enum Orders
{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
};

template<class ItemType>
class BST
{
private:
	TreeNode<ItemType> *root;
	int numberOfItemsInTree;
	std::queue<ItemType> preQueue;
	std::queue<ItemType> inQueue;
	std::queue<ItemType> postQueue;
public:
	BST();
	BST(const BST<ItemType> &targetBST);
	~BST();
	void insertItem(const ItemType item);
	void deleteItem(const ItemType item);
	bool findItem(const ItemType item) const;
	bool isEmpty() const;
	bool isFull() const;
	void resetQueue(Orders order);
	bool getNextItem(Orders order, ItemType &item);
	unsigned int getLength() const;
	BST<ItemType> operator=(BST<ItemType> &targetTree);
	friend void copyTree(const BST<ItemType> &dstTree, const BST<ItemType> &srcTree);
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
