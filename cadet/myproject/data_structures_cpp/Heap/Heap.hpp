#ifndef __HEAP_HPP__
#define __HEAP_HPP__

static const int ROOT_IDX = 1;

class FULL_HEAP{};
class EMPTY_HEAP{};

template<class ItemType>
static void swap(ItemType &a, ItemType &b)
{
	ItemType tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<class ItemType>
class Heap
{
private:
	unsigned int maxSize;
	unsigned int currentSize;
	ItemType *datas;
public:
	Heap();
	Heap(const unsigned int maxSize);
	Heap(Heap<ItemType> &srcHeap);
	~Heap();
	bool isEmpty() const;
	bool isFull() const;
	void insertItem(ItemType item);
	void deleteItem(ItemType item);
	void copyHeap(Heap<ItemType> &dstHeap, Heap<ItemType> &srcHeap);
	void reHeapUp(const unsigned int root, const unsigned int bottom);
	void reHeapDown(const unsigned int root, const unsigned int bottom);
	void heapify();
	ItemType getTop() const;
	ItemType pop();
	void operator=(Heap<ItemType> &srcHeap);
};

template<class ItemType>
Heap<ItemType>::Heap()
{
	(this->maxSize) = 1000;
	(this->datas) = new ItemType[(this->maxSize)];
	(this->currentSize) = 0;
}

template<class ItemType>
Heap<ItemType>::Heap(const unsigned int maxSize)
{
	(this->datas) = new ItemType[maxSize];
	(this->currentSize) = 0;
}

template<class ItemType>
Heap<ItemType>::Heap(Heap<ItemType> &srcHeap)
{
	(this->maxSize) = srcHeap.maxSize;
	(this->datas) = new ItemType[(this->maxSize)];
	copyHeap(*(this), srcHeap);
}

template<class ItemType>
Heap<ItemType>::~Heap()
{
	delete[] (this->datas);
}

template<class ItemType>
bool Heap<ItemType>::isEmpty() const
{
	return ((this->currentSize) == 0);
}

template<class ItemType>
bool Heap<ItemType>::isFull() const
{
	return ((this->currentSize) >= (this->maxSize));
}

template<class ItemType>
void Heap<ItemType>::insertItem(ItemType item)
{
	if ((this->isFull()))
	{
		throw (FULL_HEAP());
	}
	++(this->currentSize);
	(this->datas)[(this->currentSize)] = item;
	reHeapUp(1, (this->currentSize)); // 맨 아래에 있는 노드를 끌어올림
}

template<class ItemType>
void Heap<ItemType>::deleteItem(ItemType item)
{
	if ((this->isEmpty()))
	{
		throw (EMPTY_HEAP());
	}
	// have to find item
	unsigned int searchIdx = 0;
	ItemType* &heapData = (this->datas);
	for (unsigned int idxOfNode = ROOT_IDX; idxOfNode <= (this->currentSize); ++idxOfNode)
	{
		if (heapData[idxOfNode] == item)
		{
			searchIdx = idxOfNode;
			break ;
		}
	}
	if (searchIdx == 0) // NOT FOUND
	{
		return ;
	}
	else // FOUND
	{
		ItemType &bottomItem = heapData[(this->currentSize)];
		ItemType &targetItem = heapData[searchIdx];
		swap(targetItem, bottomItem);
		--(this->currentSize);
		// HEAPIFIY
		reHeapDown(ROOT_IDX, (this->currentSize));
	}
}


template<class ItemType>
void Heap<ItemType>::reHeapUp(const unsigned int root, const unsigned int bottom)
{
	if (bottom <= root)
		return ;
	ItemType &targetItem = this->datas[bottom];
	ItemType &parentItem = this->datas[bottom / 2];
	if (targetItem < parentItem)
	{
		return ;
	}
	else
	{
		swap(targetItem, parentItem);
		reHeapUp(ROOT_IDX, bottom / 2);
	}
}

template<class ItemType>
void Heap<ItemType>::reHeapDown(const unsigned int root, const unsigned int bottom)
{
	if (root > bottom)
		return ;
	const int LEFT_IDX = root * 2;
	const int RIGHT_IDX = root * 2 + 1;

	ItemType &rootItem = (this->datas)[root];
	ItemType &leftItem = (this->datas)[LEFT_IDX];
	ItemType &rightItem = (this->datas)[RIGHT_IDX];

	if (rootItem < leftItem && LEFT_IDX <= bottom)
	{
		swap(rootItem, leftItem);
		reHeapDown(LEFT_IDX, bottom);
	}
	if (rootItem < rightItem && RIGHT_IDX <= bottom)
	{
		swap(rootItem, rightItem);
		reHeapDown(RIGHT_IDX, bottom);
	}
}

template<class ItemType>
ItemType Heap<ItemType>::getTop() const
{
	if (this->isEmpty())
		throw (EMPTY_HEAP());
	return (this->datas[ROOT_IDX]);
}

template<class ItemType>
ItemType Heap<ItemType>::pop()
{
	ItemType item;
	ItemType &rootItem = (this->datas)[ROOT_IDX];
	ItemType &bottomItem = (this->datas)[(this->currentSize)];

	item = rootItem;
	swap(rootItem, bottomItem);
	--(this->currentSize);
	this->heapify();
	return (item);
}

template<class ItemType>
void Heap<ItemType>::heapify()
{
	reHeapDown(1, (this->currentSize));
}

template<class ItemType>
void Heap<ItemType>::operator=(Heap<ItemType> &srcHeap)
{
	if ((this->currentSize) != 0 || ((this->maxSize) < srcHeap.maxSize))
		throw (FULL_HEAP());
	copyHeap(*(this), srcHeap);
}

template<class ItemType>
void copyHeap(Heap<ItemType> &dstHeap, Heap<ItemType> &srcHeap)
{
	for (unsigned int idx = 0; idx < srcHeap.currentSize; ++idx)
	{
		(dstHeap->datas)[idx] = (srcHeap.datas)[idx];
	}
	(dstHeap->currentSize) = srcHeap.currentSize;
}

#endif
