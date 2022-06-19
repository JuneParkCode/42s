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

void selectionSort(int arr[], const int size)
{
	for (int i = 0; i < (size - 1); ++i)
	{
		int min = arr[i];
		int minIdx = i;
		for (int j = i; j < size; ++j)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minIdx = j;
			}
		}
		swapValues(arr[minIdx], arr[i]);
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
	selectionSort(arr, SIZE);
	printArr(arr, SIZE);
}
