#include <iostream>
#include <string>

using namespace std;
enum Status{ valid = 0, inValid = 1 };

int gStatus = valid;

int StrToInt(const string& str)
{
	gStatus = valid;
	int size = str.size();
	if (size == 0)
	{
		gStatus = inValid;
		return 0;
	}
	//��ͷ�����ո����� 
	int index = 0;
	while (str[index] == ' ' || str[index] == '\t')
	{
		if (index == size - 1)
		{
			gStatus = inValid;
			return 0;
		}
		++index;
	}

	//��һ����Ч�ַ�ֻ����Ϊ+��-����������
	int number = 0;
	bool isPositive = true;

	if (str[index] == '+')
		isPositive = true;
	else if (str[index] == '-')
		isPositive = false;
	else if (str[index] >= '0' && str[index] <= '9')
		number = str[index] - '0';
	else
	{
		gStatus = inValid;
		return 0;
	}
	//�ڶ�����Ч�ַ��Լ��Ժ�ֻ����Ϊ���֣�����һ����Ч
	for (int i = index + 1; i <= size - 1; ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = 10 * number + str[i] - '0';
		else
		{
			gStatus = inValid;
			return 0;
		}
		//�������
//		if (isPositive && number > 0x7fffffff || !isPositive && number < (unsigned)0x80000000)
//		{
//			gStatus = inValid;
//			return 0;
//		}
	}

	if (!isPositive)
		number = 0 - number;
	return number;

}

void Test(const string& s)
{
	int num = StrToInt(s);
	if (gStatus == inValid)
		cout << "��Ч" << num << endl;
	else
		cout << num << endl;
}

int main()
{
	Test("");
	Test("hello");
	Test("  -23f");
	Test("66666666666666666666666666666666666666666");
	//Test("-66666666666666666666666666666666666666666");
	Test(" -23333");
	Test("  +151");
	Test("151515155");

	return 0;
}

