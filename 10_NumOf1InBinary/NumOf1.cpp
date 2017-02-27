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
	// 输入0，期待的输出是0
	Test(0, 0);

	// 输入1，期待的输出是1
	Test(1, 1);

	// 输入10，期待的输出是2
	Test(10, 2);

	// 输入0x7FFFFFFF，期待的输出是31
	Test(0x7FFFFFFF, 31);

	// 输入0xFFFFFFFF（负数），期待的输出是32
	Test(0xFFFFFFFF, 32);

	// 输入0x80000000（负数），期待的输出是1
	Test(0x80000000, 1);

	return 0;
}
