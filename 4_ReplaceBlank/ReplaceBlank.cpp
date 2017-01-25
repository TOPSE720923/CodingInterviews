#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//len is actual capacity of str
void ReplaceBlank(char str[], int len)
{
	if (str == nullptr || len <= 0)
		return;
	int numOfBlank = 0;
	int oldLen = 0;
	char *p = str;
	while (*p != '\0')
	{
		++oldLen;
		if (*p == ' ')
			++numOfBlank;
		++p;
	}
	oldLen++;//size of str (including '\0')
	int newLen = oldLen + 2 * numOfBlank;//size of new str
	if (newLen > len)
		return;
	int pos = oldLen - 1;
	int newPos = newLen - 1;
	while (pos >= 0 && newPos > pos)
	{
		if (str[pos] == ' ')
		{
			str[newPos--] = '0';
			str[newPos--] = '2';
			str[newPos--] = '%';
			pos--;
		}
		else
		{
			str[newPos--] = str[pos--];
		}
	}
}

void Test()
{
	char str[100] = " we are happy";
	ReplaceBlank(str, 100);
	printf("%s", str);
}

int main()
{
	Test();
	return 0;
}
