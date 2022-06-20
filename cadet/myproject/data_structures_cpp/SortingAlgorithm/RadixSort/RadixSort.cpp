#include <random>
#include <iostream>
#include <queue>

using namespace std;

void swapValues(int &a, int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int getMaxDigits(int arr[], const int size, const int e)
{
	int max = arr[0];
	for (int i = 0; i < size; ++i)
	{
		int target = arr[i] < 0 ? -arr[i] : arr[i];
		max = max < target ? target : max;
	}
	int res = 0;
	while (max)
	{
		max /= e;
		++res;
	}
	return (res);
}

void radixSort(int arr[], const int size, const int e)
{
	queue<int> radixQueuePos[e];
	queue<int> radixQueueNeg[e + 1];
	int pass = 0;
	int div = 1;
	const int max_digits = getMaxDigits(arr, size, e);
	while (pass < max_digits)
	{
		for (int i = 0; i < size; ++i)
		{
			if (arr[i] < 0)
			{
				radixQueueNeg[(arr[i] / div) % e + e].push(arr[i]);
			}
			else
				radixQueuePos[(arr[i] / div) % e].push(arr[i]);
		}
		int idx = 0;
		for (int i = 0; i < e; ++i)
		{
			while (!radixQueueNeg[i].empty())
			{
				arr[idx++] = radixQueueNeg[i].front();
				radixQueueNeg[i].pop();
			}
		}
		for (int i = 0; i < e; ++i)
		{
			while (!radixQueuePos[i].empty())
			{
				arr[idx++] = radixQueuePos[i].front();
				radixQueuePos[i].pop();
			}
		}
		++pass;
		div *= e;
	}
}

void fillRandomNumber(int arr[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		int x = random() % 1000;
		x *= ((random() % 2 == 0) ? 1 : -1);
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
	const int SIZE = 400;
	int arr[SIZE];

	fillRandomNumber(arr, SIZE);
	printArr(arr, SIZE);
	radixSort(arr, SIZE, 10);
	printArr(arr, SIZE);
}
