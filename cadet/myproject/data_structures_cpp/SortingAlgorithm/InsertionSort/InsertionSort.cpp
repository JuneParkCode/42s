#include <iostream>
#include <random>
#include <time.h>

using namespace std;

void swapValues(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void insertionSort(int arr[], const int size)
{
	for (int i = 1; i < size; ++i)
	{
		int target = arr[i];
		int emptySpace = i;
		for (int j = i - 1 ; j >= 0; --j)
		{
			if (arr[j] > target)
			{
				swapValues(arr[j], arr[j + 1]);
				emptySpace = j;
			}
			else
			{
				break ;
			}
		}
		arr[emptySpace] = target;
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
	const int SIZE = 20;
	int arr[SIZE];

	fillRandomNumber(arr, SIZE);
	insertionSort(arr, SIZE);
	printArr(arr, SIZE);
}
