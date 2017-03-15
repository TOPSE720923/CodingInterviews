#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool IsPostOrderOfBST(int* a, int n)
{
	if (a == nullptr || n <= 0)
		return false;
	int root = a[n - 1];
	int i = 0;
	for (; i < n - 1; ++i)
	{
		if (a[i] > root)
			break;
	}
	int j = i;
	for (; j < n - 1; ++j)
	{
		if (a[j] < root)
			return false;
	}
	bool left = true;
	bool right = true;
	if (i > 0)
		left = IsPostOrderOfBST(a, i);
	if (i < n - 1)
		right = IsPostOrderOfBST(a + i, n - i - 1);
	return right && left;

}


int main()
{
	int a[] = { 5, 7, 6, 9, 11, 10, 8 };
	int sz = sizeof(a) / sizeof(a[0]);
	cout << IsPostOrderOfBST(a, sz) << endl;

	int b[] = { 7,4,6,5};
	int sz2 = sizeof(b) / sizeof(b[0]);
	cout << IsPostOrderOfBST(b, sz2) << endl;

	return 0;
}
