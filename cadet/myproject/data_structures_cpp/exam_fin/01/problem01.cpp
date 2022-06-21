#include <iostream>
#include "QueType.h"
using namespace std;

#define QUEUE_SIZE 10
#define MAX_BIT 32

void radix_sort(int*);

void print_data(int *data)
{
	for (int i = 0; i < QUEUE_SIZE; ++i)
		cout << data[i] << " ";
}

int main()
{
	int data[] = {95, 672, 15068, 65, 984, 124, 5012, 13, 16, 4};
	radix_sort(data);
	print_data(data);
	return 0;
}

void radix_sort(int* data)
{
	QueType bucket_for_bit_0(QUEUE_SIZE);
	QueType bucket_for_bit_1(QUEUE_SIZE);
	
	// ...write the code ... ;
	int mask =1;
	for (int i = 0; i < MAX_BIT; i++)
	{
		for (int j = 0; j < QUEUE_SIZE; j++)
		{
			// ...write the code ... ;
			int x = data[j] >> i;
			if (x & 1)
			{
				bucket_for_bit_1.Enqueue(data[j]);
				// ...write the code ... ;
			}
			else
			{
				bucket_for_bit_0.Enqueue(data[j]);
				// ...write the code ... ;
			}
		}
		// ...write the code ... ;

		int index = 0;
		int temp_item = 0;
		while (bucket_for_bit_0.IsEmpty() == 0)
		{
			int x;
			bucket_for_bit_0.Dequeue(x);
			data[index++] = x;
			/*
			* 
			*  ...write the code ... ;
			* 
			*/		
		}
		while (bucket_for_bit_1.IsEmpty() == 0)
		{
			int x;
			bucket_for_bit_1.Dequeue(x);
			data[index++] = x;
			/*
			*
			*  ...write the code ... ;
			*
			*/
		}
	}
}