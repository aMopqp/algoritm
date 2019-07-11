#include <stdio.h>

void BubbleSort(int *arr, int len, int *e, int i);
void CoutBubbleSort(int *arr, int len, int *e, int i, int *k);

void swap(int *a, int *b)

{

	*a ^= *b;

	*b ^= *a;

	*a ^= *b;

}

void StartBubbleSort(int *arr, int len)         //workout 1

{

	int e = 0;

	int i = 0;

	BubbleSort(arr, len, &e, i);

}

int CoutStartBubbleSort(int *arr, int len)       //workout 1.5

{

	int k = 0;

	int e = 0;

	int i = 0;

	CoutBubbleSort(arr, len, &e, i, &k);

	return k;

}

void BubbleSort(int *arr, int len, int *e, int i)

{

	if (*e<len)

	{

		if (arr[*e]>arr[*e + 1])

		{

			swap(arr + *e, arr + *e + 1);

			*e = (*e>0) ? *e - 1 : ++i;

		}

		else { i++; *e = i; }

		BubbleSort(arr, len, e, i);

	}

}

void CoutBubbleSort(int *arr, int len, int *e, int i, int *k) 

{

	if (*e<len-1)

	{
		*k+=1;
		if (arr[*e]>arr[*e + 1])

		{

			swap(arr + *e, arr + *e + 1);

			*e = (*e>0) ? *e - 1 : ++i;

		}

		else { i++; *e = i; }

		CoutBubbleSort(arr, len, e, i, k);

	}

}

void SheikerSort(int *arr, int len)       //workout 2

{	

	int i = 0;

	int j = 0;

	while (i <(len / 2) + 1)

	{

		for (j += 1; j<len - 1 - i; j++)

			if (arr[j]>arr[j + 1])

				swap(arr + j, arr + j + 1);

		for (j -= 1; j>i; j--)

			if (arr[j]<arr[j - 1])

				swap(arr + j, arr + j - 1);

		i++;

	}

}

int CoutSheikerSort(int *arr, int len)         //workout 2.5

{
	int k = 0;

	int i = 0;

	int j = 0;

	while (i <(len / 2) + 1)

	{

		for (j += 1; j < len - 1 - i; j++)
		{
			k++;

			if (arr[j] > arr[j + 1])

				swap(arr + j, arr + j + 1);
		}

		for (j -= 1; j > i; j--)
		{
			k++;
			if (arr[j] < arr[j - 1])

				swap(arr + j, arr + j - 1);
		}
		i++; 

	}
	return k;

}

int LineSeek(int *arr, int len, int v, int i)            //workout 3

{

	if (i<len && arr[i] != v)

		return LineSeek(arr, len, v, i + 1);

	else if (arr[i] == v) return i-1;

	else return -1;

}

int main(int argc, char *argv[])

{
	const len = 17;
	int a[] = { 23,7,4,8,1,6,7,2,9,4,32,12,66,54,89,2,1 };
	int a2[] = { 35,84,22,98,67,1,4,74,26,7,88,59,63,7,5,2,44 };
	int b = CoutStartBubbleSort(a2, len);                            //96 iteration
	int c = CoutSheikerSort(a, len);                                 //135 iteration
	int a3[] = { 23,7,4,8,1,6,7,2,9,4,32,12,66,54,89,2,1 };
	printf("%d iterathion , Element 23 have i=%d\n", c, LineSeek(a,len,23,0));
	printf("%d iterathion in BubleSort",CoutStartBubbleSort(a3,len));         // 70 iteration
	
	return 0;

}