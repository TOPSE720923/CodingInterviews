#include <iostream>
#include <assert.h>
#include <exception>

using namespace std;

//int BinarySearch(int *a, int n, int key)
//{
//	if (a == nullptr || n <= 0)
//		throw exception("invalid parameters");
//	int left = 0;
//	int right = n - 1;
//	while (left <= right)
//	{
//		int mid = left + ((right - left) >> 1);
//		if (a[mid] < key)
//			left = mid + 1;
//		else if (a[mid] > key)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}


int FindMinInArray(int *a, int index1, int index2)
{
	int min = a[0];
	for (int i = index1 + 1; i <= index2; ++i)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}


int MinNumInRotatedArray(int *a, int n)
{
	if (a == nullptr || n <= 0)
		throw std::exception("invalid parameters");
	int index1 = 0;
	int index2 = n - 1;

	while (a[index1] > a[index2])
	{
		if (index2 - index1 == 1)
			return a[index2];
		int midIndex = index1 + ((index2 - index1) >> 1);
		if (a[index1] == a[midIndex] && a[midIndex] == a[index2])
			return FindMinInArray(a, index1, index2);

		if (a[midIndex] > a[index1]) //a[midIndex] is in the first part of the array
		{
			index1 = midIndex;
		}
		else if (a[midIndex] < a[index2])//a[midIndex] is in the second part of the array
		{
			index2 = midIndex;
		}
	}
	//like 12345 , just return the first element as min
	return a[0];
}

void Test(int* numbers, int length, int expected)
{
	int result = 0;
	try
	{
		result = MinNumInRotatedArray(numbers, length);

		for (int i = 0; i < length; ++i)
			printf("%d ", numbers[i]);

		if (result == expected)
			printf("\tpassed\t");
		else
			printf("\tfailed\t");
		cout << result << endl;
	}
	catch (...)
	{
		if (numbers == NULL)
			printf("Test passed.\n");
		else
			printf("Test failed.\n");
	}
}


void All_Test()
{
	// 典型输入，单调升序的数组的一个旋转
	int array1[] = { 3, 4, 5, 1, 2 };
	Test(array1, sizeof(array1) / sizeof(int), 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	int array2[] = { 3, 4, 5, 1, 1, 2 };
	Test(array2, sizeof(array2) / sizeof(int), 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	int array3[] = { 3, 4, 5, 1, 2, 2 };
	Test(array3, sizeof(array3) / sizeof(int), 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	int array4[] = { 1, 0, 1, 1, 1 };
	Test(array4, sizeof(array4) / sizeof(int), 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	int array5[] = { 1, 2, 3, 4, 5 };
	Test(array5, sizeof(array5) / sizeof(int), 1);

	// 数组中只有一个数字
	int array6[] = { 2 };
	Test(array6, sizeof(array6) / sizeof(int), 2);

	// 输入NULL
	Test(NULL, 0, 0);
}

int main()
{
	All_Test();
	return 0;
} 
