#include <iostream>
using namespace std;

//递归 短路求值定理
int Sum_Solution(int n) {
	int ret = 0;
	n && (ret += n + Sum_Solution(n - 1));
	return ret;
}


//借助类
struct Test
{
	Test()
	{
		x++;
		sum += x;
	}

	static int x;
	static int sum;
};

int Test::x = 0;
int Test::sum = 0;

int Sum_Solution(int n)
{
	Test* p = new Test[n];
	int ret = p[n - 1].sum;
	delete[] p;
	return ret;
}