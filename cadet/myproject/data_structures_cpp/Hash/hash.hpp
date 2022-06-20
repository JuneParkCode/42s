#ifndef __HASH_HPP__
# define __HASH_HPP__

class FULL_MAP{};
// using Linear probing

const int MAX_SIZE = 1000;

template <class KEY, class VALUE>

struct
{
	bool valid = true;
	KEY key;
	VALUE item;
} Node; 

template <class KEY, class VALUE>
class hash
{
private:
	Node *items[MAX_SIZE];
	
	int hash(KEY key)
	{
		return (key % MAX_SIZE);
	}

	// find node that has equal key
	Node *linearProbing(KEY key)
	{
		int hashID = hash(key);
		int idx = hashID;

		do
		{
			if (items[idx]->valid && items[idx]->key == key)
			{
				return (items[idx]);
			}
			idx = (idx + 1) % MAX_SIZE;
		} while (idx != hashID);
		return (nullptr);
	}
	
	int findEmptySpace(KEY key)
	{
		int hashID = hash(key);
		
		while (items[hashID] != nullptr && items[hashID]->valid)
		{
			hashID = (hashID + 1) % MAX_SIZE;
		} // IF FULL, IT WILL BE NOT BREAK
		return (hashID);
	}

public:
	hash()
	{
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			items[i] = nullptr;
		}
	}
	~hash()
	{
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			if (items[i] != nullptr)
			{
				delete (items[i]);
			}
		}
	}
	void insert(KEY key, VALUE item)
	{
		// Can't insert
		if (isFull())
			throw (FULL_MAP());
		// already exists
		if (linearProbing(key) != nullptr)
			return ; 

		int emptySpaceIdx = findEmptySpace(key);
		
		Node *newNode = new Node();
		newNode->key = key;
		newNode->item = item;
		item[emptySpaceIdx] = newNode;
	}

	void deleteItem(KEY key)
	{
		// for linearProbing, delete space can't not be nullptr
		Node *foundNode = linearProbing(key);
		if (foundNode == nullptr)
			return ;
		else
		{
			foundNode->valid = false;
		}
	}
};


#endif
