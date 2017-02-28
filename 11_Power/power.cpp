
#include <iostream>
#include <assert.h>
#include <exception>
#include <cmath>


using namespace std;

bool Equal(double x, double y)
{
	//abs function is for integer
	if (fabs(x - y) < 0.000001)
		return true;
	else
		return false;
}


pair<double, bool> MyPower(double base, int exp)
{
	//base == 0 
	if (Equal(base, 0.0) && exp < 0)
	{
		return make_pair(0.0, false);
	}
	else if (Equal(base, 0.0) && exp > 0)
	{
		return make_pair(0.0, true);
	}
	//else if (Equal(base, 0.0) && exp == 0)
	//{
	//	return make_pair(1.0, true);
	//}

	//base != 0 and exp == 0
	if (exp == 0)
	{
		return make_pair(1.0, true);
	}

	int temp = exp;
	if (exp < 0)
	{
		temp *= -1;
	}
	double result = 1.0;
	for (int i = 0; i < temp; ++i)
	{
		result *= base;
	}

	if (exp < 0)
	{
		return make_pair(1.0 / result, true);
	}
	else
	{
		return make_pair(result, true);
	}
}

double PowerRecursion(double base, int exp)
{
	//if (exp == 0)
	//	return 0;
	if (exp == 1)
		return base;
	double ret = PowerRecursion(base, exp >> 1); //equal to exp / 2
	ret *= ret;
	if ((exp & 0x1)) // odd num   // equal to exp%2 != 0
		ret *= base;
	return ret;
}

pair<double, bool> MyPowerOptimization(double base, int exp)
{
	//base == 0 
	if (Equal(base, 0.0) && exp < 0)
	{
		return make_pair(0.0, false);
	}
	else if (Equal(base, 0.0) && exp > 0)
	{
		return make_pair(0.0, true);
	}
	//else if (Equal(base, 0.0) && exp == 0)
	//{
	//	return make_pair(1.0, true);
	//}

	//base != 0 and exp == 0
	if (exp == 0)
	{
		return make_pair(1.0, true);
	}
	int temp = exp;
	if (exp < 0)
	{
		temp *= -1;
	}
	double result = PowerRecursion(base, temp);
	if (exp < 0)
	{
		return make_pair(1 / result, true);
	}
	else
	{
		return make_pair(result, true);
	}
}

void TestPower(double base, int exp)
{
	//pair<double, bool> db = MyPower(base, exp);
	pair<double, bool> db = MyPowerOptimization(base, exp);
	cout << base << "µÄ"  << exp << "´Î·½" << db.first << ":" << boolalpha << db.second << endl;
}


void Test()
{
	TestPower(0, 1);
	TestPower(0, 0);
	TestPower(0, -1);
	TestPower(1, 0);
	TestPower(-2, 0);

	TestPower(2, 3);
	TestPower(2, -1);
	TestPower(-3, 2);
	TestPower(0.5, 2);
}

int main()
{
	Test();
	return 0;
}
