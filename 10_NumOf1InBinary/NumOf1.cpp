#include <iostream>
#include <assert.h>
#include <exception>

using namespace std;



int NumOf1(int n)
{
	int value = 1;
	int count = 0;
	while (value != 0)
	{
		if (n & value)
		{
			++count;
		}
		value <<= 1;
	}
	return count;
}

int NumberOf1(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n & (n - 1);
		++count;
	}
	return count;
}

void Test(int number, unsigned int expected)
{
	int actual = NumOf1(number);
	if (actual == expected)
		printf("Solution1: Test for %p passed.\n", number);
	else
		printf("Solution1: Test for %p failed.\n", number);

	actual = NumberOf1(number);
	if (actual == expected)
		printf("Solution2: Test for %p passed.\n", number);
	else
		printf("Solution2: Test for %p failed.\n", number);

	printf("\n");
}


int main()
{
	// ����0���ڴ��������0
	Test(0, 0);

	// ����1���ڴ��������1
	Test(1, 1);

	// ����10���ڴ��������2
	Test(10, 2);

	// ����0x7FFFFFFF���ڴ��������31
	Test(0x7FFFFFFF, 31);

	// ����0xFFFFFFFF�����������ڴ��������32
	Test(0xFFFFFFFF, 32);

	// ����0x80000000�����������ڴ��������1
	Test(0x80000000, 1);

	return 0;
}
