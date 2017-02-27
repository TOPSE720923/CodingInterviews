#include<iostream> 

using namespace std;


long long Fibonacci(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
	if (n == 2)
	 	return 2;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//f1 f2 f3 f4 f5
//1  2  3  5  8
long long FibonacciNonR(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	long long first = 1;
	long long second = 2;
	long long third = 0;
	for (int i = 3; i <= n; ++i)
	{
		third = first + second;
		first = second;
		second = third;
	}
	return third;
}

void Test(int n, int expected)
{
    if(Fibonacci(n) == expected)
        printf("Test for %d in solution1 passed.\n", n);
    else
        printf("Test for %d in solution1 failed.\n", n);

    if(FibonacciNonR(n) == expected)
        printf("Test for %d in solution2 passed.\n", n);
    else
        printf("Test for %d in solution2 failed.\n", n);
}

int main()
{
	Test(0, 0);
    Test(1, 1);
    Test(2, 2);
    Test(3, 3);
    Test(4, 5);
    Test(5, 8);
    Test(6, 13);
    Test(7, 21);
    Test(8, 34);

    return 0;
}

