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

void merge(int arr[], int leftFirst, int leftLast, int rightFirst, int rightLast)
{
	const int SIZE = rightLast - leftFirst + 1;
	int tmp[SIZE];
	int leftIdx = leftFirst;
	int rightIdx = rightFirst;
	int tmpIdx = 0;

	while (tmpIdx < SIZE)
	{
		while (leftIdx <= leftLast && (rightIdx > rightLast || arr[leftIdx] <= arr[rightIdx]))
		{
			tmp[tmpIdx++] = arr[leftIdx++];
		}
		while (rightIdx <= rightLast && (leftIdx > leftLast ||arr[leftIdx] >= arr[rightIdx]))
		{
			tmp[tmpIdx++] = arr[rightIdx++];
		}
	}
	while (tmpIdx)
	{
		arr[rightLast--] = tmp[--tmpIdx];
	}
}

void mergeSort(int arr[], int first, int last)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, last);
		cout << "MID : " << mid << " SIZE : " << last - first + 1 << endl;
		merge(arr, first, mid, mid + 1, last);
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
	mergeSort(arr, 0, SIZE - 1);
	printArr(arr, SIZE);
}
