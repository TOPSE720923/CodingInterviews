#include <iostream>
#include <assert.h>
#include <cstring>
#include <cstdio>



using namespace std;


bool Increment(char *num)
{
	int len = strlen(num);
	int numberOfPos = 0;
	int carryFlag = 0;
	for (int pos = len - 1; pos >= 0; --pos)
	{
		int numOfPos = num[pos] - '0' + carryFlag;
		if (pos == len - 1)
			++numOfPos;
		if (numOfPos == 10)
		{
			if (pos == 0)
			{
				break;
			}
			else
			{
				numOfPos -= 10;
				carryFlag = 1;
				num[pos] = numOfPos + '0';
			}
		}
		else
		{
			num[pos] = numOfPos + '0';
			return true;
		}
	}
	return false;
}

void PrintNum(char *num)
{
	assert(num != nullptr);
	int len = strlen(num);
	assert(len > 0);
	bool isFirst0 = true;
	for (int i = 0; i < len; ++i)
	{
		if (isFirst0 && num[i] != '0')
			isFirst0 = false;
		if (!isFirst0)
		{
			cout << num[i];
		}
	}
	cout << endl;
}

void PrintAllNum(int n)
{
	if (n <= 0)
		return;
	char* num = new char[n + 1];
	memset(num, '0', n);
	num[n] = '\0';

	while (Increment(num))
	{
		PrintNum(num);
	}
	delete[] num;
	num = nullptr;
}






void PrintEachNumR(char *num, int index)
{
	assert(num != nullptr && index >= 0);
	int len = strlen(num);
	if (index == len - 1)
	{
		PrintNum(num);
	}
	else
	{
		for (int i = 0; i < 10; ++i)
		{
			num[index + 1] = i + '0';
			PrintEachNumR(num, index + 1);
		}
	}
}

void PrintAllNumR(int n)
{
	assert(n > 0);
	char* num = new char[n + 1];
	num[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		num[0] = i + '0';
		PrintEachNumR(num, 0);
	}
	delete[] num;
	num = nullptr;
}


void Test()
{
	//PrintAllNum(1);
	PrintAllNumR(3);

}

int main()
{
	Test();
	return 0;
} 
