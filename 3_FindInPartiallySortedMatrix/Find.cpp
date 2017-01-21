#include <iostream>
#include <cstdio>
#include <cstring>
#include <assert.h>

using namespace std;


bool CanFind(int *a, int rows, int cols, int key)
{
	if (a == nullptr || rows <= 0 || cols <= 0)//illegal input
		return false;
	int i = 0; 
	int j = cols - 1;
	while (i <= rows - 1 && j >= 0)
	{
		if (key < a[i * cols + j])
			--j;
		else if (key > a[i * cols + j])
			++i;
		else
			return true;
	}
	return false;
}



void Test()
{
	int a[4][4] =
	{ 
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15,
	};

	//find the element that's in the matrix
	cout << boolalpha << CanFind((int *)a, 4, 4, 7) << endl;
	//find the element that's not in the matrix
	cout << boolalpha << CanFind((int *)a, 4, 4, 5) << endl;

	//find the element that's greater than max
	cout << boolalpha << CanFind((int *)a, 4, 4, 20) << endl;
	//find the element that's less than max
	cout << boolalpha << CanFind((int *)a, 4, 4, 0) << endl;


	//find the element that's max in the matrix
	cout << boolalpha << CanFind((int *)a, 4, 4, 15) << endl;
	//find the element that's min in the matrix
	cout << boolalpha << CanFind((int *)a, 4, 4, 1) << endl;
	
	//illegal input
	cout << boolalpha << CanFind(nullptr, 4, 4, 20) << endl;
	cout << boolalpha << CanFind((int *)a, 0, 4, 4) << endl;
	cout << boolalpha << CanFind((int *)a, 4, -2, 4) << endl;
}


int main()
{
	Test();
	return 0;
}
