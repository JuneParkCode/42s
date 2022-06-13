#include <iostream>
#include <random>

using namespace std;

void swap(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(int arr[], const int size)
{
	for (int i = size - 1; i >= 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

int main(void)
{
	const int SIZE = 100;
	int arr[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = random() % 10;
		cout << arr[i];
	}
	bubbleSort(arr, SIZE);
	cout << "\n";
	for (int i = 0; i < SIZE; ++i)
	{
		cout << arr[i];
	}
	return (0);
}
