#include <iostream>
using namespace std;

//递归 短路求值定理
int Sum_Solution(int n) {
	int ret = 0;
	n && (ret += n + Sum_Solution(n - 1));
	return ret;
}


//利用构造函数
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

//利用虚函数
class A;
A* arr[2];


class A
{
public:
	virtual int Sum(int n)
	{
		return 0;
	}
};

class B : public A
{
public:
	virtual int Sum(int n)
	{
		return arr[!!n]->Sum(n - 1) + n;
	}
};


int main()
{

	//cout << Sum_Solution(5) << endl;
	
	A a;
	B b;
	arr[0] = &a;
	arr[1] = &b;

	cout << b.Sum(10) << endl;


	return 0;
}

//函数指针
typedef int(*fun)(int);

int sum1(int x)
{
	return 0;
}

int sum2(int n)
{
	static fun funArr[2] = { sum1, sum2 };
	return funArr[!!n](n - 1) + n;
}