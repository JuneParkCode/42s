#include <iostream>
#include <random>

using namespace std;

void swapValues(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int split(int arr[], int first, int last)
{
	int saveFirst = first;
	int pivotValue = arr[first++];
	while (first <= last)
	{
		while (first <= last && arr[first] < pivotValue)
			++first;
		while (first <= last && arr[last] >= pivotValue)
			--last;
		if (first < last)
			swapValues(arr[first], arr[last]);
		++first;
		--last;
	}
	swapValues(arr[saveFirst], arr[last + 1]);
	return (last + 1);
}

void quickSort(int arr[], int first, int last)
{
	if (first < last)
	{
		int pivot = split(arr, first, last);
		quickSort(arr, first, pivot - 1);
		quickSort(arr, pivot + 1, last);
	}
}

void fillRandomNumber(int arr[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		int x = random() % size;
		cout << x << " ";
		arr[i] = x;
	}
}

void printArr(int arr[], const int size)
{
	cout << "\n==PRINT==\n";
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	const int SIZE = 21;
	int arr[SIZE];

	fillRandomNumber(arr, SIZE);
	printArr(arr, SIZE);
	quickSort(arr, 0, SIZE - 1);
	printArr(arr, SIZE);
}
