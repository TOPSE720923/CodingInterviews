#include <iostream>
#include <cstring>
#include <assert.h>
#include <vector>
using namespace std;


void Perm(char* s, char* beg)
{
	if (*beg == '\0')
		cout << s << endl;
	else
	{
		for (char* p = beg; *p != '\0'; ++p)
		{
			swap(*p, *beg);
			Perm(s, beg + 1);
			swap(*p, *beg);
		}
	}
}


void Perm(char* s)
{
	if (s == NULL)
		return;
	Perm(s, s);
}

static int num = 0; 

void Combination(char* s, int k, vector<char>& v)
{
	if (k == 0)
	{
		num++;
		for (int i = 0; i < (int)v.size(); ++i)
		{
			cout << v[i];
		}
		cout << endl;
		return;
	}
	if (*s == '\0')
		return;

	v.push_back(*s);
	Combination(s + 1, k-1, v);
	v.pop_back();
	Combination(s + 1, k, v);
}

void Combination(char* s)
{
	if (s == nullptr)
		return;
	vector<char> v;
	int len = strlen(s);
	for (int i = 1; i <= len; ++i)
	{
		Combination(s, i, v);
	}
}

int main()
{

	char s[] = "abc";
	Perm(s);
	Combination(s);
	cout << num << endl;
	return 0;
}
