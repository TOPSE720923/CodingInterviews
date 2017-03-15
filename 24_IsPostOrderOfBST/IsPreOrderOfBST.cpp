#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool IsPreOrderOfBST(int* a, int n)
{
	if (a == nullptr || n <= 0)
		return false;
	int root = a[0];
	int i = 1;
	for (; i < n; ++i)
	{
		if (a[i] > root)
			break;
	}
	int j = i;
	for (; j < n; ++j)
	{
		if (a[j] < root)
			return false;
	}
	bool left = true;
	bool right = true;
	if (i < n)
	{
		left = IsPreOrderOfBST(a + 1, i);
		right = IsPreOrderOfBST(a + i, n - i);
	}
	return left && right;
}


int main()
{
	int a[] = { 8, 6, 5, 7, 10, 9, 11 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << IsPreOrderOfBST(a, sz) << endl;

	int b[] = { 5,7,4,6};
	int sz2 = sizeof(b) / sizeof(b[0]);
	cout << IsPreOrderOfBST(b, sz2) << endl;
	return 0;
}

