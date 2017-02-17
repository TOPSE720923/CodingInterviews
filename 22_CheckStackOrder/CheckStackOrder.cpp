#include <iostream>
#include <assert.h>
#include <stack>
using namespace std; 

//search x in the array first and return the subscript of the array,
//if subscript == n, not found
int Find(const int *first, int n, int x)
{
	int i = 0;
	while (i != n)
	{
		if (x == first[i])
			break;
		++i;
	}
	return i;
}

bool CheckStackOrder(const int *first, const int *second, int n)
{
	assert(first != nullptr);
	assert(second != nullptr);
	assert(n <= 0);
	stack<int> s;
	int firstPos = Find(first, n, second[0]);
	if (firstPos == n)
	{
		cout << "these two sequence doesn't match" << endl;
		exit(1);
	}
	int k = 0;
	while (k <= firstPos)
	{
		s.push(first[k]);
		++k;
	}
	s.pop();
	//matched the first element

	//traverse the second array
	size_t i = 1;
	while (i != n )
	{
		if (s.top() == second[i++])
			s.pop();
		else
		{
			++firstPos; 
			if (firstPos == n)
				return false;
			s.push(first[firstPos]);
		}                                                                                 
	}
	return true;
}

int main()
{
	int first[] = {1,2,3,4,5};
	int s1[] = {4,5,3,2,1};
	int s2[] = {4,3,5,1,2};
	int n = sizeof(first) / sizeof(first[0]);
	cout << CheckStackOrder(first, s1, n) << endl;
	cout << CheckStackOrder(first, s2, n) << endl;
	
	
 	return 0;
}
