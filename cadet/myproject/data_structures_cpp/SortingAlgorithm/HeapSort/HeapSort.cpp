#include <iostream>
#include <random>

using namespace std;
template<class T>

void swapData(T &a, T &b)
{
	T t;
	t = a;
	a = b;
	b = t;
}

template<class T>
class heap
{
private:
	T *data;
	int size;
	int maxSize;
	int tmpSize;
public:
	heap()
	{
		maxSize = 100;
		data = new T[maxSize];
		size = 0;
	}
	~heap()
	{
		delete[] data;
	}
	void nodeDown()
	{
		int idx = 1;
		while (idx <= size)
		{
			T &item = data[idx];
			const int left = idx * 2;
			const int right = idx * 2 + 1;
			T &leftItem = data[left];
			T &rightItem = data[right];
			if (left <= size && right <= size)
			{
				if (leftItem <= rightItem && rightItem > item)
				{
					swapData(item, rightItem);
					idx = right;
				}
				else if (leftItem >= rightItem && leftItem > item)
				{
					swapData(item, leftItem);
					idx = left;
				}
				else
				{
					break ;
				}
			}
			else if (left <= size && right > size)
			{
				if (leftItem > item)
				{
					swapData(item, leftItem);
					idx = left;
				}
				else
				{
					break ;
				}
			}
			else
			{
				break ;
			}
		}
	}
	void nodeUp()
	{
		int idx = size;
		while (idx > 1) // until root
		{
			T &item = data[idx];
			const int parentIdx = idx / 2;
			T &parent = data[parentIdx];
			if (parent < item)
			{
				swapData(parent, item);
				idx = parentIdx;
			}
			else
			{
				break ;
			}
		}
	}
	void insert(T item)
	{
		if (size >= maxSize)
			return ;
		data[++size] = item;
		nodeUp();
		for (int i = 0; i <= size; ++i)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	T pop()
	{
		T item = data[1]; // ROOT
		swapData(data[1], data[size]);
		size--;
		nodeDown();
		return (item);
	}
};

int main(void)
{
	heap<int> myHeap;
	for (int i = 0; i < 10; ++i)
	{
		int x = random() % 10;
		cout << x << ":";
		myHeap.insert(x);
	}
	int arr[10];
	cout << '\n';
	for (int i = 10; i > 0; --i)
	{
		cout << myHeap.pop();
	}
}
