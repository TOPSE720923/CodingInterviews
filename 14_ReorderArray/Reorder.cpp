#include <iostream>
#include <assert.h>

using namespace std; 


bool IsEven(int x)
{
	return (x & 0x1) == 0;
}


void ReOrderArray(int *a, int n, bool (*fun)(int x))
{
	assert(a != nullptr && n > 0);
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		while (left < right && !fun(a[left]))
		{
			++left;
		}
		while (left < right&& fun(a[right]))
		{
			--right;
		}
		swap(a[left], a[right]);
	}
}


void ReorderOddEven(int *numbers, int length)
{
	ReOrderArray(numbers, length, IsEven);
}

void Print(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}



void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    ReorderOddEven(numbers, 7);
    Print(numbers, 7);
}

void Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    ReorderOddEven(numbers, 7);
    Print(numbers, 7);
}

void Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    ReorderOddEven(numbers, 7);
    Print(numbers, 7);
}

void Test4()
{
    int numbers[] = {1};
    ReorderOddEven(numbers, 1);
    Print(numbers, 1);
}

void Test5()
{
    int numbers[] = {2};
    ReorderOddEven(numbers, 1);
    Print(numbers, 1);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
   // Test6();

    return 0;
}

