#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

//search x in the array first and return the subscript of the array,
//if subscript == n, not found

bool CheckStackOrder(const int *first, const int *second, int n)
{
	//assert(first != nullptr && second != nullptr && n > 0);
	if (first == nullptr && second == nullptr && n <= 0)
		return false;
	stack<int> s;
	//find the pos in the first array according to the second[0]
	int i = 0;
	while (first[i] != second[0])
	{
		++i;
		if (i == n)
		{
			//the two sequence don't match
			return false;
		}
	}
	int firstPos = 0;
	while (firstPos <= i)
	{
		s.push(first[firstPos++]);
	}

	int secondPos = 0;
	while (secondPos != n)
	{
		while (s.top() != second[secondPos])
		{
			if (firstPos == n)
				return false;
			s.push(first[firstPos++]);
		}
		s.pop();
		++secondPos;
	}
	return true;
}

void Test(char* testName, const int* first, const int* second, int nLength, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (CheckStackOrder(first, second, nLength) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };
	Test("Test1", push, pop, nLength, true);
}

void Test2()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };
	Test("Test2", push, pop, nLength, true);
}

void Test3()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };
	Test("Test3", push, pop, nLength, false);
}

void Test4()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };
	Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 2 };
	Test("Test5", push, pop, nLength, false);
}

void Test6()
{
	const int nLength = 1;
	int push[nLength] = { 1 };
	int pop[nLength] = { 1 };
	Test("Test6", push, pop, nLength, true);
}

void Test7()
{
	Test("Test7", NULL, NULL, 0, false);
}



int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();

	return 0;
}
